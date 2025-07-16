#! /usr/bin/env python3

import argparse
import os
import shutil
import subprocess
import sys
from pathlib import Path
from typing import Dict, List, Set, Union

import ninja_syntax
import splat
import splat.scripts.split as split
from splat.segtypes.linker_entry import LinkerEntry

ROOT = Path(__file__).parent.resolve()
TOOLS_DIR = ROOT / "tools"

YAML_FILE = "quest64.us.yaml"
BASENAME = "quest64"
LD_PATH = f"{BASENAME}.ld"
ELF_PATH = f"build/{BASENAME}"
MAP_PATH = f"build/{BASENAME}.map"
PRE_ELF_PATH = f"build/{BASENAME}.elf"

LIBC_PATH = "src/libc"
ULTRA_OS_PATH = "src/libultra/os"
ULTRA_IO_PATH = "src/libultra/io"
ULTRA_GU_PATH = "src/libultra/gu"
ULTRA_AUDIO_PATH = "src/libultra/audio"

OVERLAYS_PATH = "src/overlays/"

#Files that compile differently from the rest of the directory they are in
SPECIAL_FILE_COMPILE_RULES = {
    "src/libc/ll.c": "libc_ll_cc",
    "src/libc/xldtob.c": "O3_G0cc",
    "src/libc/xprintf.c": "O3_G0cc",
    "src/libc/xlitob.c": "O3_G0cc",
    "src/libultra/io/sptask.c": "O2_G0cc",
    "src/libultra/audio/sndpstop.c": "O2_G0cc",
    "src/audio/drvrNew.c": "O2_G0cc",
}

COMMON_INCLUDES = "-I. -Iinclude -Iinclude/2.0H/ -Iinclude/2.0H/PR -Isrc -Isrc/libultra"
IDO_DIR = f"{TOOLS_DIR}/ido_5.3/usr/lib/cc"
CC_DIR = f"$ASM_PROC $ASM_PROC_FLAGS {IDO_DIR} --$AS $ASFLAGS"
DEFINES = "-D_LANGUAGE_C -DF3DEX_GBI -DNDEBUG -DBUILD_VERSION=VERSION_H"
WARNINGS = f"-fullwarn -verbose -Xcpluscomm -signed -nostdinc -non_shared -Wab,-r4300_mul {DEFINES} -woff 649,838"
CFLAGS = f"-G 0 {WARNINGS} {COMMON_INCLUDES}" #Might need {DEFINES} added back.
DEPENDENCY_GEN = f"cpp -w {COMMON_INCLUDES} -nostdinc -MD -MF $out.d $in -o /dev/null"

GAME_O2_G0_COMPILE = (
    f"{CC_DIR} {COMMON_INCLUDES} -- -c -G 0 {WARNINGS} {COMMON_INCLUDES} -mips2 -O2 -g0"
)

GAME_O2_G3_COMPILE = (
    f"{CC_DIR} {COMMON_INCLUDES} -- -c -G 0 {WARNINGS} {COMMON_INCLUDES} -mips2 -O2 -g3"
)

GAME_O1_G0_COMPILE = (
    f"{CC_DIR} {COMMON_INCLUDES} -- -c -G 0 {WARNINGS} {COMMON_INCLUDES} -mips2 -O1 -g0"
)

GAME_03_G0_COMPILE = (
    f"{CC_DIR} {COMMON_INCLUDES} -- -c -G 0 {WARNINGS} {COMMON_INCLUDES} -mips2 -O3 -g0"
)

LIB_COMPILE_CMD = (
    f"{CC_DIR} -c -B {CC_DIR}/ee- {COMMON_INCLUDES} -O2 -G0"
)

def exec_shell(command: List[str]) -> str:
    ret = subprocess.run(
        command, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True
    )
    return ret.stdout

def clean():
    if os.path.exists(".splache"):
        os.remove(".splache")
    shutil.rmtree("asm", ignore_errors=True)
    shutil.rmtree("assets", ignore_errors=True)
    shutil.rmtree("build", ignore_errors=True)

def write_permuter_settings():
    with open("permuter_settings.toml", "w") as f:
        f.write(
            f"""compiler_command = "{IDO_DIR} -c -G 0 {CFLAGS} -mips2 -O2"
        assembler_command = "mips-linux-gnu-as -EB -mtune=vr4300 -march=vr4300 -mabi=32"
        compiler_type = "ido"

        [preserve_macros]

        [decompme.compilers]
        "{IDO_DIR}" = "ido_5.3"
        """
        )

def build_stuff(linker_entries: List[LinkerEntry]):
    built_objects: Set[Path] = set()

    def build(
            object_paths: Union[Path, List[Path]],
            src_paths: List[Path],
            task: str,
            variables: Dict[str, str] = {},
            implicit_outputs: List[str] = [],
    ):
        if not isinstance(object_paths, list):
            object_paths = [object_paths]

        object_strs = [str(obj) for obj in object_paths]

        for object_path in object_paths:
            if object_path.suffix == ".o":
                built_objects.add(object_path)
            ninja.build(
                outputs=object_strs,
                rule=task,
                inputs=[str(s) for s in src_paths],
                variables=variables,
                implicit_outputs=implicit_outputs,
            )

    ninja = ninja_syntax.Writer(open(str(ROOT / "build.ninja"), "w"), width=9999)

    ninja.variable("ASM_PROC", "python3 tools/asm-processor/build.py")
    ninja.variable("ASM_PROC_FLAGS", "--input-enc=utf-8 --output-enc=euc-jp")
    ninja.variable("ASFLAGS", "mips-linux-gnu-as -EB -mtune=vr4300 -march=vr4300 -mabi=32")

    # Rules

    cross = "mips-linux-gnu-"

    ld_args = f"-T quest64.ld -T undefined_syms_auto.txt -T undefined_syms.txt -Map $mapfile --no-check-sections"

    ninja.rule(
        "as",
        description="as $in",
        command=f"cpp {COMMON_INCLUDES} $in -o - | {cross}as -no-pad-sections -EB -mtune=vr4300 -march=vr4300 -mabi=32 -Iinclude -o $out",
    )

    ninja.rule(
        "O2_G3cc",
        description="cc $in",
        command=f"{GAME_O2_G3_COMPILE} -o $out $in && {DEPENDENCY_GEN}",
    )

    ninja.rule(
        "overlaycc",
        description="cc (overlay) $in",
        command=f"{GAME_O2_G0_COMPILE} -o $out $in && {DEPENDENCY_GEN}",
    )

    ninja.rule(
        "O2_G0cc",
        description="cc (g0) $in",
        command=f"{GAME_O2_G0_COMPILE} -o $out $in && {DEPENDENCY_GEN}",
    )

    ninja.rule(
        "libc_ll_cc",
        description="cc libc_ll_cc .c file",
        command=f"({CC_DIR} -- -c {CFLAGS} -mips3 -32 -O1 -o $out $in) && (python3 {TOOLS_DIR}/set_o32abi_bit.py $out && {DEPENDENCY_GEN})",
    )


    ninja.rule(
        "O3_G0cc",
        command=f"{IDO_DIR} -c -G 0 -Xcpluscomm -xansi {COMMON_INCLUDES} -non_shared -mips2 -woff 819,826,852,838,649 -Wab,-r4300_mul -nostdinc -O3 -o $out $in && {DEPENDENCY_GEN}",
        description="Compiling -O3 ido .c file",
        depfile="$out.d",
        deps="gcc",
    )

    ninja.rule(
        "O1_G0cc",
        description="cc (O1) $in",
        command=f"{GAME_O1_G0_COMPILE} -o $out $in && {DEPENDENCY_GEN}",
    )

    ninja.rule(
        "ld",
        description="link $out",
        command=f"{cross}ld {ld_args} -o $out",
    )

    ninja.rule(
        "sha1sum",
        description="sha1sum $in",
        command="sha1sum -c $in && touch $out",
    )

    ninja.rule(
        "elf",
        description="elf $out",
        command=f"{cross}objcopy $in $out -O binary",
    )

    for entry in linker_entries:
        seg = entry.segment

        if seg.type[0] == ".":
            continue

        if entry.object_path is None:
            continue

        if isinstance(seg, splat.segtypes.common.asm.CommonSegAsm) or isinstance(
            seg, splat.segtypes.common.data.CommonSegData
        ):
            build(entry.object_path, entry.src_paths, "as")
        elif isinstance(seg, splat.segtypes.common.c.CommonSegC):
            # Check if any of the source file paths match a special compile rule.
                special_command = None
                for key, cmd in SPECIAL_FILE_COMPILE_RULES.items():
                    if any(str(src_path).startswith(key) for src_path in entry.src_paths):
                        special_command = cmd
                        break
                if special_command:
                    build(entry.object_path, entry.src_paths, special_command)
                elif any(str(src_path).startswith(OVERLAYS_PATH) for src_path in entry.src_paths):
                    build(entry.object_path, entry.src_paths, "overlaycc")
                elif any(str(src_path).startswith(ULTRA_AUDIO_PATH) for src_path in entry.src_paths):
                    build(entry.object_path, entry.src_paths, "O3_G0cc")
                elif any(str(src_path).startswith(ULTRA_IO_PATH) for src_path in entry.src_paths):
                    build(entry.object_path, entry.src_paths, "O1_G0cc")
                elif any(str(src_path).startswith(ULTRA_GU_PATH) for src_path in entry.src_paths):
                    build(entry.object_path, entry.src_paths, "O3_G0cc")
                elif any(str(src_path).startswith(ULTRA_OS_PATH) for src_path in entry.src_paths):
                    build(entry.object_path, entry.src_paths, "O1_G0cc")
                elif any(str(src_path).startswith(LIBC_PATH) for src_path in entry.src_paths):
                    build(entry.object_path, entry.src_paths, "O2_G0cc")
                else:
                    build(entry.object_path, entry.src_paths, "O2_G3cc")
        elif isinstance(seg, splat.segtypes.common.databin.CommonSegDatabin):
            build(entry.object_path, entry.src_paths, "as")
        else:
            print(f"ERROR: Unsupported build segment type {seg.type}")
            sys.exit(1)

    
    ninja.build(
        PRE_ELF_PATH,
        "ld",
        LD_PATH,
        implicit=[str(obj) for obj in built_objects],
        variables={"mapfile": MAP_PATH},
    )

    ninja.build(
        ELF_PATH,
        "elf",
        PRE_ELF_PATH,
    )

    ninja.build(
        ELF_PATH + ".ok",
        "sha1sum",
        "checksum.sha1",
        implicit=[ELF_PATH],
    )

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Configure the project")
    parser.add_argument(
        "-c",
        "--clean",
        help="Clean extraction and build artifacts",
        action="store_true",
    )
    args = parser.parse_args()

    if args.clean:
        clean()

    split.main([YAML_FILE], modes="all", verbose=False)

    linker_entries = split.linker_writer.entries

    build_stuff(linker_entries)

    write_permuter_settings()
    