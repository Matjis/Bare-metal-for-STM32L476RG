#include <stdio.h>

#define SRAM1_START      0x20000000U
#define SRAM1_SIZE       (96U * 1024U) // 96KB
#define SRAM1_END        ((SRAM1_START) + (SRAM1_SIZE))

/* SRAM2 starts at 0x10000000U and is (32U * 1024U) // 32KB
#define SRAM2_START      0x10000000U
#define SRAM2_SIZE       (32U * 1024U) // 32KB
#define SRAM2_END        ((SRAM2_START) + (SRAM2_SIZE))
*/

#define STACK_START     SRAM1_END

extern uint32_t _etext;
extern uint32_t _sdata;
extern uint32_t _edata;

extern uint32_t _sbss;
extern uint32_t _ebss;

//prototype for main
int main(void);

// Function prototypes of STM32L476xx system exceptions and IRQ handlers
void Reset_Handler(void);

void NMI_Handler (void) __attribute__ ((weak, alias("Default_Handler")));
void HardFault_Handler(void) __attribute__ ((weak, alias("Default_Handler")));
void MemManage_Handler(void) __attribute__ ((weak, alias("Default_Handler")));
void BusFault_Handler(void) __attribute__ ((weak, alias("Default_Handler")));
void UsageFault_Handler(void) __attribute__ ((weak, alias("Default_Handler")));
void SVCall_Handler(void) __attribute__ ((weak, alias("Default_Handler")));
void Debug_Handler(void) __attribute__ ((weak, alias("Default_Handler")));
void PendSV_Handler(void) __attribute__ ((weak, alias("Default_Handler")));
void SysTick_Handler(void) __attribute__ ((weak, alias("Default_Handler")));
void WWDG_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void PVD_PVM_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void RTC_TAMP_STAMP_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void RTC_WKUP_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void FLASH_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void RCC_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void EXTI0_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void EXTI1_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void EXTI2_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void EXTI3_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void EXTI4_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void DMA1_CH1_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void DMA1_CH2_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void DMA1_CH3_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void DMA1_CH4_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void DMA1_CH5_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void DMA1_CH6_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void DMA1_CH7_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void ADC1_2_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void CAN1_TX_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void CAN1_RX0_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void CAN1_RX1_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void CAN1_SCE_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void EXTI9_5_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void TIM1_BRK_TIM15_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void TIM1_UP_TIM16_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void TIM1_TRG_COM_TIM17_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void TIM1_CC_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void TIM2_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void TIM3_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void TIM4_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void I2C1_EV_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void I2C1_ER_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void I2C2_EV_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void I2C2_ER_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void SPI1_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void SPI2_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void USART1_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void USART2_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void USART3_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void EXTI15_10_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void RTC_ALARM_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void DFSDM1_FLT3_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void TIM8_BRK_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void TIM8_UP_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void TIM8_TRG_COM_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void TIM8_CC_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void ADC3_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void FMC_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void SDMMC1_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void TIM5_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void SPI3_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void UART4_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void UART5_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void TIM6_DACUNDER_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void TIM7_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void DMA2_CH1_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void DMA2_CH2_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void DMA2_CH3_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void DMA2_CH4_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void DMA2_CH5_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void DFSDM1_FLT0_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void DFSDM1_FLT1_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void DFSDM1_FLT2_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void COMP_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void LPTIM1_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void LPTIM2_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void OTG_FS_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void DMA2_CH6_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void DMA2_CH7_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void LPUART1_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void QUADSPI_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void I2C3_EV_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void I2C3_ER_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void SAI1_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void SAI2_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void SWPMI1_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void TSC_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void LCD_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void AES_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void RNG_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void FPU_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));




uint32_t vectors[] __attribute__((section(".isr_vector"))) = {
    STACK_START,
    (uint32_t)Reset_Handler,
    (uint32_t)NMI_Handler,
    (uint32_t)HardFault_Handler,
    (uint32_t)MemManage_Handler,
    (uint32_t)BusFault_Handler,
    (uint32_t)UsageFault_Handler,
    0,
    0,
    0,
    0,    
    (uint32_t)SVCall_Handler,
    (uint32_t)Debug_Handler,
    0,
    (uint32_t)PendSV_Handler,
    (uint32_t)SysTick_Handler,
    (uint32_t)WWDG_IRQHandler,             			    /* Window Watchdog interrupt                                           */
    (uint32_t)PVD_PVM_IRQHandler,           			/* PVD through EXTI line detection                                     */
    (uint32_t)RTC_TAMP_STAMP_IRQHandler,        		/* Tamper and TimeStamp interrupts                                     */
    (uint32_t)RTC_WKUP_IRQHandler,          			/* RTC Tamper or TimeStamp /CSS on LSE through EXTI line 19 interrupts */
    (uint32_t)FLASH_IRQHandler,             			/* Flash global interrupt                                              */
    (uint32_t)RCC_IRQHandler,               			/* RCC global interrupt                                                */
    (uint32_t)EXTI0_IRQHandler,             			/* EXTI Line 0 interrupt                                               */
    (uint32_t)EXTI1_IRQHandler,             			/* EXTI Line 1 interrupt                                               */
    (uint32_t)EXTI2_IRQHandler,             			/* EXTI Line 2 interrupt                                               */
    (uint32_t)EXTI3_IRQHandler,             			/* EXTI Line 3 interrupt                                               */
    (uint32_t)EXTI4_IRQHandler,             			/* EXTI Line 4 interrupt                                               */
    (uint32_t)DMA1_CH1_IRQHandler,          			/* DMA1 Channel1 global interrupt                                      */
    (uint32_t)DMA1_CH2_IRQHandler,          			/* DMA1 Channel2 global interrupt                                      */
    (uint32_t)DMA1_CH3_IRQHandler,          			/* DMA1 Channel3 interrupt                                             */
    (uint32_t)DMA1_CH4_IRQHandler,          			/* DMA1 Channel4 interrupt                                             */
    (uint32_t)DMA1_CH5_IRQHandler,          			/* DMA1 Channel5 interrupt                                             */
    (uint32_t)DMA1_CH6_IRQHandler,          			/* DMA1 Channel6 interrupt                                             */
    (uint32_t)DMA1_CH7_IRQHandler,          			/* DMA1 Channel 7 interrupt                                            */
    (uint32_t)ADC1_2_IRQHandler,            			/* ADC1 and ADC2 global interrupt                                      */
    (uint32_t)CAN1_TX_IRQHandler,           			/* CAN1 TX interrupts                                                  */
    (uint32_t)CAN1_RX0_IRQHandler,          			/* CAN1 RX0 interrupts                                                 */
    (uint32_t)CAN1_RX1_IRQHandler,          			/* CAN1 RX1 interrupts                                                 */
    (uint32_t)CAN1_SCE_IRQHandler,          			/* CAN1 SCE interrupt                                                  */
    (uint32_t)EXTI9_5_IRQHandler,           			/* EXTI Line5 to Line9 interrupts                                      */
    (uint32_t)TIM1_BRK_TIM15_IRQHandler,    			/* TIM1 Break/TIM15 global interrupts                                  */
    (uint32_t)TIM1_UP_TIM16_IRQHandler,     			/* TIM1 Update/TIM16 global interrupts                                 */
    (uint32_t)TIM1_TRG_COM_TIM17_IRQHandler,			/* TIM1 Trigger and Commutation interrupts and TIM17 global interrupt  */
    (uint32_t)TIM1_CC_IRQHandler,           			/* TIM1 Capture Compare interrupt                                      */
    (uint32_t)TIM2_IRQHandler,              			/* TIM2 global interrupt                                               */
    (uint32_t)TIM3_IRQHandler,              			/* TIM3 global interrupt                                               */
    (uint32_t)TIM4_IRQHandler,              			/* TIM4 global interrupt                                               */
    (uint32_t)I2C1_EV_IRQHandler,           			/* I2C1 event interrupt                                                */
    (uint32_t)I2C1_ER_IRQHandler,           			/* I2C1 error interrupt                                                */
    (uint32_t)I2C2_EV_IRQHandler,           			/* I2C2 event interrupt                                                */
    (uint32_t)I2C2_ER_IRQHandler,           			/* I2C2 error interrupt                                                */
    (uint32_t)SPI1_IRQHandler,              			/* SPI1 global interrupt                                               */
    (uint32_t)SPI2_IRQHandler,              			/* SPI2 global interrupt                                               */
    (uint32_t)USART1_IRQHandler,            			/* USART1 global interrupt                                             */
    (uint32_t)USART2_IRQHandler,            			/* USART2 global interrupt                                             */
    (uint32_t)USART3_IRQHandler,            			/* USART3 global interrupt                                             */
    (uint32_t)EXTI15_10_IRQHandler,         			/* EXTI Lines 10 to 15 interrupts                                      */
    (uint32_t)RTC_ALARM_IRQHandler,         			/* RTC alarms through EXTI line 18 interrupts                          */
    (uint32_t)DFSDM1_FLT3_IRQHandler,       			/* DFSDM1_FLT3 global interrupt                                        */
    (uint32_t)TIM8_BRK_IRQHandler,          			/* TIM8 Break Interrupt                                                */
    (uint32_t)TIM8_UP_IRQHandler,           			/* TIM8 Update Interrupt                                               */
    (uint32_t)TIM8_TRG_COM_IRQHandler,      			/* TIM8 Trigger and Commutation Interrupt                              */
    (uint32_t)TIM8_CC_IRQHandler,           			/* TIM8 Capture Compare Interrupt                                      */
    (uint32_t)ADC3_IRQHandler,              			/* ADC3 global interrupt                                               */
    (uint32_t)FMC_IRQHandler,               			/* FMC global Interrupt                                                */
    (uint32_t)SDMMC1_IRQHandler,            			/* SDMMC global Interrupt                                              */
    (uint32_t)TIM5_IRQHandler,              			/* TIM5 global Interrupt                                               */
    (uint32_t)SPI3_IRQHandler,              			/* SPI3 global Interrupt                                               */
    (uint32_t)UART4_IRQHandler,             			/* UART4 global Interrupt                                              */
    (uint32_t)UART5_IRQHandler,             			/* UART5 global Interrupt                                              */
    (uint32_t)TIM6_DACUNDER_IRQHandler,     			/* TIM6 global and DAC1 and 2 underrun error interrupts                */
    (uint32_t)TIM7_IRQHandler,              			/* TIM7 global interrupt                                               */
    (uint32_t)DMA2_CH1_IRQHandler,          			/* DMA2 Channel 1 global Interrupt                                     */
    (uint32_t)DMA2_CH2_IRQHandler,          			/* DMA2 Channel 2 global Interrupt                                     */
    (uint32_t)DMA2_CH3_IRQHandler,          			/* DMA2 Channel 3 global Interrupt                                     */
    (uint32_t)DMA2_CH4_IRQHandler,          			/* DMA2 Channel 4 global Interrupt                                     */
    (uint32_t)DMA2_CH5_IRQHandler,          			/* DMA2 Channel 5 global Interrupt                                     */
    (uint32_t)DFSDM1_FLT0_IRQHandler,       			/* DFSDM1_FLT0 global interrupt                                        */
    (uint32_t)DFSDM1_FLT1_IRQHandler,       			/* DFSDM1_FLT1 global interrupt                                        */
    (uint32_t)DFSDM1_FLT2_IRQHandler,       			/* DFSDM1_FLT2 global interrupt                                        */
    (uint32_t)COMP_IRQHandler,              			/* COMP1 and COMP2 interrupts                                          */
    (uint32_t)LPTIM1_IRQHandler,            			/* LP TIM1 interrupt                                                   */
    (uint32_t)LPTIM2_IRQHandler,            			/* LP TIM2 interrupt                                                   */
    (uint32_t)OTG_FS_IRQHandler,            			/* USB OTG FS global Interrupt                                         */
    (uint32_t)DMA2_CH6_IRQHandler,          			/* DMA2 Channel 6 global Interrupt                                     */
    (uint32_t)DMA2_CH7_IRQHandler,          			/* DMA2 Channel 7 global Interrupt                                     */
    (uint32_t)LPUART1_IRQHandler,           			/* LPUART1 global interrupt                                            */
    (uint32_t)QUADSPI_IRQHandler,           			/* Quad SPI global interrupt                                           */
    (uint32_t)I2C3_EV_IRQHandler,           			/* I2C3 event interrupt                                                */
    (uint32_t)I2C3_ER_IRQHandler,           			/* I2C3 error interrupt                                                */
    (uint32_t)SAI1_IRQHandler,              			/* SAI1 global interrupt                                               */
    (uint32_t)SAI2_IRQHandler,              			/* SAI2 global interrupt                                               */
    (uint32_t)SWPMI1_IRQHandler,            			/* SWPMI1 global interrupt                                             */
    (uint32_t)TSC_IRQHandler,               			/* TSC global interrupt                                                */
    (uint32_t)LCD_IRQHandler,               			/* LCD global interrupt                                                */
    (uint32_t)AES_IRQHandler,               			/* AES global interrupt                                                */
    (uint32_t)RNG_IRQHandler,               			/* RNG and HASH global interrupt                                       */
    (uint32_t)FPU_IRQHandler,               			/* Floating point interrupt                                            */

 
};

void Default_Handler(void){

    while(1);
}

void Reset_Handler(void){

    // copy .data section to SRAM
    uint32_t size = (uint32_t)&_edata - (uint32_t)&_sdata;

    uint8_t *pDst = (uint8_t*)&_sdata;
    uint8_t *pSrc = (uint8_t*)&_etext; //Flash

    for(uint32_t i=0; i < size; i++){
        
        *pDst++ = *pSrc++;
    }

    // init the .bss section to zero in SRAM
    size = &_ebss - &_sbss;
    pDst = (uint8_t*)&_sbss;

    for(uint32_t i=0; i < size; i++){
        
        *pDst++ = 0;
    }

    //call init function of std. library if needed

    main();


}