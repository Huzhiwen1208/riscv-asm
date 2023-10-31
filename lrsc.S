.text
.globl lrsc_ins
lrsc_ins:
    lr.w t0, (a0)
    bne t0, a1, failed

    sc.w a0, t0, (a0)
    jr ra 

failed:
    addi a0, zero, 1
    jr ra