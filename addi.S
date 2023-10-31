.text
.globl addi_ins
.globl addi_ins_2

# add rd, rs, imm; imm ∈(-2048, 2047) rd rs为通用寄存器
addi_ins:
    addi a0, a0, 5
    jr ra

addi_ins_2:
    addi a0, a0, -2048
    jr ra
    
#  Error: illegal operands `addi a0,a0,2048'
# addi_ins_3:
#     addi a0, a0, 2048   
#     jr ra


.globl addi_reg
.globl sub_reg
# add rd, rs1, rs2
addi_reg:
    add a0, a0, a1
    jr ra

# sub rd, rs1, rs2
sub_reg:
    sub a0, a0, a1
    jr ra