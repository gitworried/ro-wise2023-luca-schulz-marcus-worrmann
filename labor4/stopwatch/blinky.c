#include "blinky.h"
#include "base.h"
// Register

// RCC
static volatile uint32_t *const RCC_AHB1ENR = (uint32_t *)(RCC_BASE + 0x58);
static volatile uint32_t *const RCC_AHB2ENR = (uint32_t *)(RCC_BASE + 0x4c);

// GPIO
static volatile uint32_t *const GPIO_MODER = (uint32_t *)(GPIOB_BASE);
static volatile uint32_t *const GPIO_ODR = (uint32_t *)(GPIOB_BASE + 0x14);
static volatile uint32_t *const GPIO_IDR = (uint32_t *)(GPIOB_BASE + 0x10);

// SysTick
static volatile uint32_t *const STK_CNTRL = (uint32_t *)(STK_BASE + 0x00);
static volatile uint32_t *const STK_LOAD = (uint32_t *)(STK_BASE + 0x04);
static volatile uint32_t *const STK_VAL = (uint32_t *)(STK_BASE + 0x08);
// Funktionen

void set_register(volatile uint32_t *reg, int bitmask, int not_bitmask)
{
  *reg = not_bitmask;
  *reg |= bitmask;
}

void led_init()
{
  set_register(RCC_AHB2ENR, RCC_AHB2ENR_PB, (1 << 1));
  set_register(GPIO_MODER, GPIO_MODER_LD3, (0b00 << 6));
  set_register(STK_LOAD, STK_1HZ, 1);
  set_register(STK_VAL, 0, 0);
  set_register(STK_CNTRL, STK_INIT, 1);
}

void led_set(int val)
{
  set_register(GPIO_ODR, (val << 3), (0 << 3));
}

void led_toggle()
{
  *GPIO_ODR ^= (1 << 3);
}


volatile uint32_t *const stk_value()
{
  return STK_VAL;
}

int button()
{
  if (*GPIO_IDR & ~(1 << 3))
    return 1;
  return 0;
}

void clock_on()
{
  *STK_CNTRL |= 1;
}

void clock_off()
{
  *STK_CNTRL &= ~(1);
}

void clock_toggle()
{
  if (*STK_CNTRL & 1)
  {
    clock_off();
    led_set(1);
    set_register(STK_VAL, 0, 0);
  }
  else
    clock_on();
}

void wfi()
{
  __asm__ volatile("WFI" : : : "memory");
}