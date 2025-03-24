        .text
        .align  1
        .globl  bubblesort
        .type   bubblesort, @function

bubblesort:
        li      t0, 1
        ble     a1, t0, .L2
        mv      t5, a0
        addi    t0, a1, -1
.L_outer:
        li      t1, 0
        
.L_inner:
        slli    t2, t1, 2
        add     t2, t5, t2
        lw      t3, 0(t2)
        lw      t4, 4(t2)
        ble     t3, t4, .L_no_swap
        sw      t4, 0(t2)
        sw      t3, 4(t2)
.L_no_swap:
        addi    t1, t1, 1
        blt     t1, t0, .L_inner
        addi    t0, t0, -1
        bgt     t0, zero, .L_outer

.L2:
        li      a0, 0
        ret
        .size   bubblesort, .-bubblesort
