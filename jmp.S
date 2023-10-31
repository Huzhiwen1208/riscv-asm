.text

.globl jal_ins
jal_ins:
    jal a0, option
    nop

option:
    nop
    nop
    jr ra


.globl jalr_ins
jalr_ins:
    addi sp, sp, -4
    sw ra, 0(sp)
    jalr ra, a0, 0 # ra = [nop], pc = a0+0
    nop
    lw ra, 0(sp)
    addi sp, sp, 4
    jr ra 

nop_option:
    nop
    nop
    jr ra

.globl beq_ins 
beq_ins:
    beq a0, a1, option0
    jal x5, option1

.globl bne_ins
bne_ins:
    bne a0, a1, option0
    jal x5, option1

option0:
    addi a0, zero, 0
    jr ra 

option1:
    addi a0, zero, 1
    jr ra 

