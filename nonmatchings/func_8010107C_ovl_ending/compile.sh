#!/usr/bin/env bash
INPUT="$(realpath "$1")"
OUTPUT="$(realpath "$3")"
cd /home/mallos31/Quest64-Decomp
'$ASM_PROC' '$ASM_PROC_FLAGS' /home/mallos31/Quest64-Decomp/tools/ido_5.3/usr/lib/cc '--$AS' '$ASFLAGS' -I. -Iinclude -Iinclude/2.0I/ -Iinclude/2.0I/PR -Isrc -- -c -G 0 -fullwarn -verbose -Xcpluscomm -signed -nostdinc -non_shared -Wab,-r4300_mul -D_LANGUAGE_C -DF3DEX_GBI -DNDEBUG -woff 649,838 -I. -Iinclude -Iinclude/2.0I/ -Iinclude/2.0I/PR -Isrc -mips2 -O2 "$INPUT" -o "$OUTPUT"