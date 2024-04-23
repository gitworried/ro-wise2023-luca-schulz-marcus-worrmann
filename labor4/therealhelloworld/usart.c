#include "usart.h"

// Bitmasks
#define RCC_AHB2ENR_GPIOA_EN (1)
#define RCC_APB1ENR1_USART2_EN (1 << 17)

#define GPIOA_MODER_MODE2_PA2_AFM (0b10 << 4)
#define GPIOA_MODER_MODE15_PA15_AFM (0b10 << 30)

#define GPIO2_AFRL_AFSEL2 (0b0111 << 8)
#define GPIOA_AFLH_AFSEL15 (0b0111 << 28)

#define USART_ISR_TXE (1 << 7)
#define USART_ISR_TC (1 << 6)

#define USART_CR1_UE (1)
#define USART_CR1_TE (1 << 3)

// Base register
#define USART2_BASE 0x40004400
#define RCC_BASE 0x40021000
#define GPIOA_BASE 0x48000000

// register

// USART2
static volatile uint32_t *const usart2_isr = (uint32_t *)(USART2_BASE + 0x1c);
static volatile uint32_t *const usart2_tdr = (uint32_t *)(USART2_BASE + 0x28);
static volatile uint32_t *const usart2_cr1 = (uint32_t *)(USART2_BASE);
static volatile uint32_t *const usart2_brr = (uint32_t *)(USART2_BASE + 0x0c);

// RCC
static volatile uint32_t *const rcc_apb1enr1 = (uint32_t *)(RCC_BASE + 0x58);
static volatile uint32_t *const rcc_ahb2enr = (uint32_t *)(RCC_BASE + 0x4c);

// GPIO
static volatile uint32_t *const gpioa_moder = (uint32_t *)(GPIOA_BASE);
static volatile uint32_t *const gpioa_afrl = (uint32_t *)(GPIOA_BASE + 0x20);
static volatile uint32_t *const gpioa_afrh = (uint32_t *)(GPIOA_BASE + 0x24);

// Functions
void usart_putc(uint8_t c)
{
    while (!(*(usart2_isr)&USART_ISR_TXE))
        ;
    *usart2_tdr = c;
    while (!(*(usart2_isr)&USART_ISR_TC))
        ;
}

void usart_puts(const char *str)
{
    char c;
    while ((c = *str++))
    {
        usart_putc(c);
    }
    usart_putc(13);
}

void usart_putx(uint32_t val)
{
    uint8_t tmp;
    for (int i = 7; i >= 0; i--)
    {
        tmp = (val >> i * 4) & 15;
        if (tmp < 10)
            usart_putc(tmp + 48);
        if (tmp >= 10)
            usart_putc(tmp + 55);
        usart_putc(13);
    }
}

void usart_init()
{
    *rcc_ahb2enr &= ~(0b11);
    *rcc_ahb2enr |= RCC_AHB2ENR_GPIOA_EN; // Enable GPIOA Port

    *rcc_apb1enr1 &= ~(1 << 17);
    *rcc_apb1enr1 |= RCC_APB1ENR1_USART2_EN; // Enable USART2

    *gpioa_moder &= ~(0b11 << 4);              // Clear PA2
    *gpioa_moder |= GPIOA_MODER_MODE2_PA2_AFM; // Set PA2 to Alternate-Function-Mode

    *gpioa_afrl &= ~(0b1111 << 8);    // Clear PA2 AF
    *gpioa_afrl |= GPIO2_AFRL_AFSEL2; // Set PA2 as USART (bx0111 in bit 11 - 8)

    *usart2_cr1 &= ~(1 << 28); // Set M1 Bit in USART_CR1 to 0
    *usart2_cr1 &= ~(1 << 12); // Set M0 Bit in USART_CR1 to 0

    *usart2_cr1 &= ~(1 << 15); // Set oversampling to 16 bit

    *usart2_brr = 0x22;          // Set baud rate in USART_BRR to 115200
    *usart2_cr1 |= USART_CR1_UE; // Enable USART2
    *usart2_cr1 |= USART_CR1_TE; // Set TE Bit to 1 to send idle frame
}
