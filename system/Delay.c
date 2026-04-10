#include <driverlib.h>

#define MCLK_MHZ 1         //系统默认时钟是1MHZ

void Delay_us(uint32_t us)
{
    uint32_t i;
    for(i = 0; i < us; i++)
    {
        __delay_cycles(MCLK_MHZ * 1);
    }
}

void Delay_ms(uint32_t ms)
{
    uint32_t i;
    for(i = 0; i < ms; i++)
    {
        __delay_cycles(MCLK_MHZ * 1000);
    }
}