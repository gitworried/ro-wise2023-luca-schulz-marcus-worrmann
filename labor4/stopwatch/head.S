.global _start
.global _systick

.equ STACK_HIGH, 0x20010000

Vectors:
    .word STACK_HIGH
    .word _start + 1
    .org 0x003C
    .word _systick + 1
