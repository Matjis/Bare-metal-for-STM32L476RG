#include<stdio.h>

//register address
#define RCC_BASE_ADDR 							0x40021000UL
#define RCC_AHB2_ENR_OFFSET						0x4CUL
#define RCC_AHB2_ENR_ADDR  						(RCC_BASE_ADDR + RCC_AHB2_ENR_OFFSET)
//*(volatile uint32_t *)

#define GPIOA_BASE_ADDR							0x48000000UL // led2 uses pa5 pin and has to be output to supply current
#define GPIOA_MODE_REG 							(GPIOA_BASE_ADDR + 0x00)
#define GPIOA_SPEED_REG 						(GPIOA_BASE_ADDR + 0x08)
#define GPIOA_PUPD_REG 							(GPIOA_BASE_ADDR + 0x0C)
#define GPIOA_OPTYPE_REG 						(GPIOA_BASE_ADDR + 0x04)
#define GPIOA_OUTPUTDATA_REG 					(GPIOA_BASE_ADDR + 0x14)
#define BuiltInLED								5
#define ExtLED									6

void delay(void){
	for(uint32_t i=0; i < 500000/2 ; i++);
}

int main(void)
{
	// Enable RCC for GPIOA
	uint32_t *pRccAhb2Enr = (uint32_t*) (RCC_AHB2_ENR_ADDR);
	*pRccAhb2Enr |= (1 << 0);

	// Reset and set GPIOA mode to output
	uint32_t *GPIOA_MDOE = (uint32_t*) (GPIOA_MODE_REG);
	*GPIOA_MDOE &= ~( 3 << ( ExtLED *2) );
	*GPIOA_MDOE |= ( 1 << (ExtLED *2) ) ;

	//
	uint32_t *GPIOA_SPEED = (uint32_t*) (GPIOA_SPEED_REG );
	*GPIOA_SPEED &= ~( 3 << ( ExtLED *2) );
	*GPIOA_SPEED |= ( 2 << ( ExtLED *2) ) ;

	//
	uint32_t *GPIOA_PUPD = (uint32_t*) (GPIOA_PUPD_REG);
	*GPIOA_PUPD &= ~( 3 << ( ExtLED *2) );
	*GPIOA_PUPD |= ( 1 << ( ExtLED *2) ) ;

	//
	uint32_t *GPIOA_OPTYPE = (uint32_t*) (GPIOA_OPTYPE_REG );
	*GPIOA_OPTYPE &= ~( 1 << ExtLED );
	*GPIOA_OPTYPE |= ( 1 << ExtLED) ;

	//
	uint32_t *GPIOA_OUTPUTDATA = (uint32_t*) (GPIOA_OUTPUTDATA_REG );
	//*GPIOA_OUTPUTDATA &= ~( 1 << 5 );


	while(1){
		*GPIOA_OUTPUTDATA ^= ( 1 << ExtLED) ;
		delay();
	}
}

