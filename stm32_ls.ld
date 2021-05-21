ENTRY(Reset_Handler)

MEMORY
{
    FLASH(rx):ORIGIN =0x08000000,LENGTH =1024K
    SRAM1(rwx):ORIGIN =0x20000000,LENGTH =96K
    SRAM2(rwx):ORIGIN =0x10000000,LENGTH =32K
}

SECTIONS
{
    .text :
    {
        *(.isr_vector)
        *(.text)
        *(.rodata)
        . = ALIGN(4);
        _etext = .; 
    }> FLASH

    .data : 
    {
        _sdata = .;
        *(.data)
        . = ALIGN(4);
        _edata = .;
    }> SRAM1 AT> FLASH

    .bss :
    {
        _sbss = .; 
        *(.bss)
        _ebss = .;
    }> SRAM1
}