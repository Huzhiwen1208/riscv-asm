.text
.globl andi_ins
.globl and_ins
.globl ori_ins
.globl or_ins
.globl xori_ins
.globl xor_ins

andi_ins:
    andi a0, a0, 0xff
    jr ra

and_ins:
    and a0, a0, a1
    jr ra

ori_ins:
    ori a0, a0, 0xff
    jr ra

or_ins:
    or a0, a0, a1
    jr ra

xori_ins:
    xori a0, a0, 0xff
    jr ra

xor_ins:
    xor a0, a0, a1
    jr ra


.globl slli_ins
.globl sll_ins
.globl srli_ins
.globl srl_ins
.globl srai_ins
.globl sra_ins

slli_ins:
    slli a0, a0, 0x1
    jr ra

sll_ins:
    sll a0, a0, a1
    jr ra

srli_ins:
    srli a0, a0, 0x1
    jr ra
    
srl_ins:
    srl a0, a0, a1
    jr ra

srai_ins:
    srai a0, a0, 0x1
    jr ra

sra_ins:
    sra a0, a0, a1
    jr ra
    