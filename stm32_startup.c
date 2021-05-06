#include <stdio.h>

#define SRAM1_START      0x20000000U
#define SRAM1_SIZE       (96U * 1024U) // 96KB
#define SRAM1_END        ((SRAM1_START) + (SRAM1_SIZE))

// SRAM2 starts at 0x10000000U and is (32U * 1024U) // 32KB

#define STACK_START     SRAM1_END

void Reset_handler(void);
void NMI_handler(void) __attribute__ ((weak, alias("Default_handler")));
void HardFault_handler(void) __attribute__ ((weak, alias("Default_handler")));


uint32_t vectors[] __attribute__((section(".isr.vector")))= {
    STACK_START,
    (uint32_t)&Reset_handler,
    (uint32_t)&NMI_handler,




};


void Default_handler(void){
    while(1);
}

void Reset_handler(void){



}