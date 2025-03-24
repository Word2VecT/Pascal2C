   	.arch armv7-a
	.text
	.global	bubblesort
	.syntax unified
	.thumb
	.thumb_func
bubblesort:
    push    {r4, r5, r6, r7, lr}
    
    mov     r2, #0
    cmp     r1, #1
    ble     .Ldone

.Louter:
    cmp     r2, r1
    bge     .Ldone
    
    mov     r3, #0
    sub     r4, r1, r2
    sub     r4, r4, #1

.Linner:
    cmp     r3, r4
    bge     .Linner_done
    
    lsl     r5, r3, #2
    add     r6, r0, r5
    ldr     r5, [r6]
    ldr     r7, [r6, #4]
    
    cmp     r5, r7
    ble     .Lno_swap
    
    str     r7, [r6]
    str     r5, [r6, #4]

.Lno_swap:
    add     r3, r3, #1
    b       .Linner

.Linner_done:
    add     r2, r2, #1
    b       .Louter

.Ldone:
    mov     r0, #0
    pop     {r4, r5, r6, r7, pc}
