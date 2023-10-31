.text
# 比较指令
.globl slti_ins
.globl sltiu_ins
slti_ins:
    slti a0, a0, 5 # a0 = (a0 < 5) ? 1 : 0
    jr ra

sltiu_ins:
    sltiu a0, a0, -100 # a0 = (a0 < unsigned(-100)) ? 1 : 0
    jr ra


.globl slt_reg
.globl sltu_reg
slt_reg:
    slt a0, a0, a1 # a0 = (a0 < a1) ? 1 : 0
    jr ra

sltu_reg:
    sltu a0, a0, a1 # a0 = (a0 < a1) ? 1 : 0
    jr ra
