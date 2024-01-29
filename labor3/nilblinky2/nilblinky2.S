    .global _start
    .syntax unified
      /* The following values are adapted to the Nucleo L432KC
   * any other model may need adjustments */
  .equ STACK_HIGH,          0x20010000

  /* Relevant addresses and values for the RCC register bank */
  .equ RCC_BASE,            0x40021000
  .equ RCC_AHB2ENR,         RCC_BASE + 0x4c
  .equ RCC_AHB2ENR_PB,      (1<<1)

  /* Relevant addresses and values of the GPIOB register bank */
  .equ GPIOB_BASE,          0x48000400
  .equ GPIOB_MODER,         GPIOB_BASE + 0x00
  .equ GPIO_MODER_PIN0O,    0x01
  .equ GPIO_MODER_PIN1I,    (00<<1)
  .equ GPIOB_ODR,           GPIOB_BASE + 0x14
  .equ GPIOB_IDR,           GPIOB_BASE + 0x10 //GPIO port input data register

  .equ DIT_LENGTH,          0x50A80
  .equ DAH_LENGTH,          0xF1F09

  .equ SYMBOL_SPACE,        DIT_LENGTH
  .equ LETTER_SPACE,        DAH_LENGTH
  .equ WORD_SPACE,          0x23481B

Vectors:
    .word STACK_HIGH
    .word _start + 1    /* initial sp value */

_delay:
  subs  r3, r3, #1
  bne _delay
  bx  lr

_EMIT_SIGNAL:
  mov r4, lr
  str r1, [r2] //LED on

  bl _delay

  str r0, [r2]  //LED off

  mov lr, r4
  bx lr

_start:
  ldr r0, =0x00 //reset LED
  ldr r1, =0b01 //set LED
    
  /* Get contents of AHB1 bus clock enable register */
  ldr     r2, =RCC_AHB2ENR
  ldr     r3, [r2]

  /* Set bit to enable clock for GPIO port B */
  ldr     r4, =RCC_AHB2ENR_PB
  orrs    r3, r4
  str     r3, [r2]

  /* Configure GPIO pin as output or input */
  ldr     r2, =GPIOB_MODER
  ldr     r3, =GPIO_MODER_PIN0O
  ldr     r4, =GPIO_MODER_PIN1I
  orr     r3, r4
  str     r3, [r2]
  /* Load address of GPIOB output data register in r2 */
  ldr     r2, =GPIOB_ODR
  /* Load address of GPIOB input data register in r5 */
  ldr     r5, =GPIOB_IDR

  .mainLoop:
    ldr r6, [r5] //load input data from register
    and r6, (1<<1) //and-link with bitmask 0b0000 0010
    subs r6, (1<<1) //subtract result with bitmask
    beq .mainLoop //repeat from .mainLoop if the result is 0

  //NIL-Sequence
  //DAH-Signal
  ldr r3, =DAH_LENGTH //copies the DAH_LENGTH-value into the parameter-register(r3)
  bl _EMIT_SIGNAL //calls the _EMIT_SIGNAL-function
  ldr r3, =SYMBOL_SPACE 
  bl _delay

  //DIT-Signal
  ldr r3, =DIT_LENGTH
  bl _EMIT_SIGNAL

  //letter space
  ldr r3, =LETTER_SPACE
  bl _delay

  //DIT-Signal
  ldr r3, =DIT_LENGTH
  bl _EMIT_SIGNAL
  ldr r3, =SYMBOL_SPACE
  bl _delay

  //DIT-Signal
  ldr r3, =DIT_LENGTH
  bl _EMIT_SIGNAL

  //letter space
  ldr r3, =LETTER_SPACE
  bl _delay  

  //DIT-Signal
  ldr r3, =DIT_LENGTH
  bl _EMIT_SIGNAL
  ldr r3, =SYMBOL_SPACE
  bl _delay

  //DAH-Signal
  ldr r3, =DAH_LENGTH
  bl _EMIT_SIGNAL
  ldr r3, =SYMBOL_SPACE
  bl _delay

  //DIT-Signal
  ldr r3, =DIT_LENGTH
  bl _EMIT_SIGNAL
  ldr r3, =SYMBOL_SPACE
  bl _delay

  //DIT-Signal
  ldr r3, =DIT_LENGTH
  bl _EMIT_SIGNAL

  //word space
  ldr r3, =WORD_SPACE
  bl _delay

  b .mainLoop
