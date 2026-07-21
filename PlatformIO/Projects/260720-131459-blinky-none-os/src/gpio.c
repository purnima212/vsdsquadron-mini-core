#include "gpio.h"

#define BLINKY_GPIO_PORT GPIOD
#define BLINKY_GPIO_PIN  GPIO_Pin_6

static uint8_t ledState = 0;

void gpio_init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure = {0};

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE);

    GPIO_InitStructure.GPIO_Pin = BLINKY_GPIO_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;

    GPIO_Init(BLINKY_GPIO_PORT, &GPIO_InitStructure);
}

void gpio_set(void)
{
    GPIO_WriteBit(BLINKY_GPIO_PORT, BLINKY_GPIO_PIN, Bit_SET);
}

void gpio_clear(void)
{
    GPIO_WriteBit(BLINKY_GPIO_PORT, BLINKY_GPIO_PIN, Bit_RESET);
}

void gpio_toggle(void)
{
    ledState ^= 1;
    GPIO_WriteBit(BLINKY_GPIO_PORT,
                  BLINKY_GPIO_PIN,
                  (BitAction)ledState);
}