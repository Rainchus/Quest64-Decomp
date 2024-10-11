.set noat
.set noreorder
.set gp=64
.macro glabel label
    .global \label
    .type \label, @function
    \label:
.endm

.macro dlabel label
    .global \label
    \label:
.endm

.macro jlabel label
    \label:
.endm

# Float register aliases (o32 ABI)

.set $fv0,          $f0
.set $fv0f,         $f1
.set $fv1,          $f2
.set $fv1f,         $f3
.set $ft0,          $f4
.set $ft0f,         $f5
.set $ft1,          $f6
.set $ft1f,         $f7
.set $ft2,          $f8
.set $ft2f,         $f9
.set $ft3,          $f10
.set $ft3f,         $f11
.set $fa0,          $f12
.set $fa0f,         $f13
.set $fa1,          $f14
.set $fa1f,         $f15
.set $ft4,          $f16
.set $ft4f,         $f17
.set $ft5,          $f18
.set $ft5f,         $f19
.set $fs0,          $f20
.set $fs0f,         $f21
.set $fs1,          $f22
.set $fs1f,         $f23
.set $fs2,          $f24
.set $fs2f,         $f25
.set $fs3,          $f26
.set $fs3f,         $f27
.set $fs4,          $f28
.set $fs4f,         $f29
.set $fs5,          $f30
.set $fs5f,         $f31
glabel func_8010107C_ovl_ending
/* E288BC 8010107C 00047080 */  sll        $t6, $a0, 2
/* E288C0 80101080 01C47021 */  addu       $t6, $t6, $a0
/* E288C4 80101084 3C0F8015 */  lui        $t7, %hi(D_80156FE8)
/* E288C8 80101088 25EF6FE8 */  addiu      $t7, $t7, %lo(D_80156FE8)
/* E288CC 8010108C 000E7100 */  sll        $t6, $t6, 4
/* E288D0 80101090 01CF1021 */  addu       $v0, $t6, $t7
/* E288D4 80101094 8C580000 */  lw         $t8, 0x0($v0)
/* E288D8 80101098 0018C800 */  sll        $t9, $t8, 0
/* E288DC 8010109C 07220004 */  bltzl      $t9, .L801010B0_ovl_ending
/* E288E0 801010A0 8C430038 */   lw        $v1, 0x38($v0)
/* E288E4 801010A4 03E00008 */  jr         $ra
/* E288E8 801010A8 00001025 */   or        $v0, $zero, $zero
/* E288EC 801010AC 8C430038 */  lw         $v1, 0x38($v0)
.L801010B0_ovl_ending:
/* E288F0 801010B0 3C01437F */  lui        $at, (0x437F0000 >> 16)
/* E288F4 801010B4 44816000 */  mtc1       $at, $f12
/* E288F8 801010B8 44832000 */  mtc1       $v1, $f4
/* E288FC 801010BC C4480048 */  lwc1       $f8, 0x48($v0)
/* E28900 801010C0 94480032 */  lhu        $t0, 0x32($v0)
/* E28904 801010C4 468021A0 */  cvt.s.w    $f6, $f4
/* E28908 801010C8 25090001 */  addiu      $t1, $t0, 0x1
/* E2890C 801010CC 312AFFFF */  andi       $t2, $t1, 0xFFFF
/* E28910 801010D0 A4490032 */  sh         $t1, 0x32($v0)
/* E28914 801010D4 0143082A */  slt        $at, $t2, $v1
/* E28918 801010D8 46066003 */  div.s      $f0, $f12, $f6
/* E2891C 801010DC 46004280 */  add.s      $f10, $f8, $f0
/* E28920 801010E0 E44A0048 */  swc1       $f10, 0x48($v0)
/* E28924 801010E4 C4420048 */  lwc1       $f2, 0x48($v0)
/* E28928 801010E8 4602603E */  c.le.s     $f12, $f2
/* E2892C 801010EC 00000000 */  nop
/* E28930 801010F0 45030004 */  bc1tl      .L80101104_ovl_ending
/* E28934 801010F4 E44C0048 */   swc1      $f12, 0x48($v0)
/* E28938 801010F8 14200003 */  bnez       $at, .L80101108_ovl_ending
/* E2893C 801010FC 00000000 */   nop
/* E28940 80101100 E44C0048 */  swc1       $f12, 0x48($v0)
.L80101104_ovl_ending:
/* E28944 80101104 C4420048 */  lwc1       $f2, 0x48($v0)
.L80101108_ovl_ending:
/* E28948 80101108 54A00006 */  bnel       $a1, $zero, .L80101124_ovl_ending
/* E2894C 8010110C 46026481 */   sub.s     $f18, $f12, $f2
/* E28950 80101110 4600140D */  trunc.w.s  $f16, $f2
/* E28954 80101114 440C8000 */  mfc1       $t4, $f16
/* E28958 80101118 10000006 */  b          .L80101134_ovl_ending
/* E2895C 8010111C A44C004E */   sh        $t4, 0x4E($v0)
/* E28960 80101120 46026481 */  sub.s      $f18, $f12, $f2
.L80101124_ovl_ending:
/* E28964 80101124 4600910D */  trunc.w.s  $f4, $f18
/* E28968 80101128 440E2000 */  mfc1       $t6, $f4
/* E2896C 8010112C 00000000 */  nop
/* E28970 80101130 A44E004E */  sh         $t6, 0x4E($v0)
.L80101134_ovl_ending:
/* E28974 80101134 944F0032 */  lhu        $t7, 0x32($v0)
/* E28978 80101138 8C580038 */  lw         $t8, 0x38($v0)
/* E2897C 8010113C 01F8082A */  slt        $at, $t7, $t8
/* E28980 80101140 5420000D */  bnel       $at, $zero, .L80101178_ovl_ending
/* E28984 80101144 00001025 */   or        $v0, $zero, $zero
/* E28988 80101148 44803000 */  mtc1       $zero, $f6
/* E2898C 8010114C A4400032 */  sh         $zero, 0x32($v0)
/* E28990 80101150 14A00005 */  bnez       $a1, .L80101168_ovl_ending
/* E28994 80101154 E4460048 */   swc1      $f6, 0x48($v0)
/* E28998 80101158 241900FF */  addiu      $t9, $zero, 0xFF
/* E2899C 8010115C A459004E */  sh         $t9, 0x4E($v0)
/* E289A0 80101160 03E00008 */  jr         $ra
/* E289A4 80101164 240200FF */   addiu     $v0, $zero, 0xFF
.L80101168_ovl_ending:
/* E289A8 80101168 A440004E */  sh         $zero, 0x4E($v0)
/* E289AC 8010116C 03E00008 */  jr         $ra
/* E289B0 80101170 240200FF */   addiu     $v0, $zero, 0xFF
/* E289B4 80101174 00001025 */  or         $v0, $zero, $zero
.L80101178_ovl_ending:
/* E289B8 80101178 03E00008 */  jr         $ra
/* E289BC 8010117C 00000000 */   nop
