#include <ch32v00x.h>
#include <debug.h>
#include <gpio.h>

#define BLINKY_GPIO_PORT GPIOD
#define BLINKY_GPIO_PIN GPIO_Pin_6
#define BLINKY_CLOCK_ENABLE RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE)

void NMI_Handler(void) __attribute__((interrupt("WCH-Interrupt-fast")));
void HardFault_Handler(void) __attribute__((interrupt("WCH-Interrupt-fast")));
void Delay_Init(void);
void Delay_Ms(uint32_t n);

int main(void)
{
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
	SystemCoreClockUpdate();
	Delay_Init();

	USART_Printf_Init(115200);

	gpio_init();

	printf("\r\n");
	printf("====================================\r\n");
	printf("VSDSquadron Mini\r\n");
	printf("Firmware Version : 1.0\r\n");
	printf("====================================\r\n");

	//GPIO_InitTypeDef GPIO_InitStructure = {0};

	//BLINKY_CLOCK_ENABLE;
	//GPIO_InitStructure.GPIO_Pin = BLINKY_GPIO_PIN;
	//GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	//GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	//GPIO_Init(BLINKY_GPIO_PORT, &GPIO_InitStructure);

	uint8_t ledState = 0;
	uint32_t counter =1;
	
	while (1)
	{
		//GPIO_WriteBit(BLINKY_GPIO_PORT, BLINKY_GPIO_PIN, ledState);
		gpio_toggle();
		//ledState ^= 1; // invert for the next run
		
		 printf("Counter : %lu\r\n", counter++);
		
		Delay_Ms(1000);
	}
}

void NMI_Handler(void) {}
void HardFault_Handler(void)
{
	while (1)
	{
	}
}
