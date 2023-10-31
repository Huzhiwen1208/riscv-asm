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
