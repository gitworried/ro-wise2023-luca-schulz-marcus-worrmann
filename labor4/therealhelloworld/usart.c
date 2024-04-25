#include "usart.h"
#include "base.h"

// register

// USART2
static volatile uint32_t *const USART2_ISR = (uint32_t *)(USART2_BASE + 0x1c);
static volatile uint32_t *const USART2_TDR = (uint32_t *)(USART2_BASE + 0x28);
static volatile uint32_t *const USART2_CR1 = (uint32_t *)(USART2_BASE);
static volatile uint32_t *const USART2_BRR = (uint32_t *)(USART2_BASE + 0x0c);

// RCC
static volatile uint32_t *const RCC_AHB1ENR = (uint32_t *)(RCC_BASE + 0x58);
static volatile uint32_t *const RCC_AHB2ENR = (uint32_t *)(RCC_BASE + 0x4c);

// GPIO
static volatile uint32_t *const gpioa_moder = (uint32_t *)(GPIOA_BASE);
static volatile uint32_t *const gpioa_afrl = (uint32_t *)(GPIOA_BASE + 0x20);
static volatile uint32_t *const gpioa_afrh = (uint32_t *)(GPIOA_BASE + 0x24);

// Functions
void usart_putc(uint8_t c)
{
    while (!(*(USART2_ISR)&USART_ISR_TXE))
        ;
    *USART2_TDR = c;
    while ((!USART2_ISR) & USART_ISR_TC)
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
    *RCC_AHB2ENR &= ~(0b11);
    *RCC_AHB2ENR |= RCC_AHB2ENR_GPIOA_EN;

    *RCC_AHB1ENR &= ~(1 << 17);
    *RCC_AHB1ENR |= RCC_AHB1ENR_USART2_EN;

    *gpioa_moder &= ~(0b11 << 4);
    *gpioa_moder |= GPIOA_MODER_MODE2_PA2_AFM;

    *gpioa_afrl &= ~(0b1111 << 8);
    *gpioa_afrl |= GPIO2_AFRL_AFSEL2;

    *USART2_CR1 &= ~(1 << 28);
    *USART2_CR1 &= ~(1 << 12);

    *USART2_CR1 &= ~(1 << 15);

    *USART2_BRR = 0x22;
    *USART2_CR1 |= USART_CR1_UE;
    *USART2_CR1 |= USART_CR1_TE;
}
