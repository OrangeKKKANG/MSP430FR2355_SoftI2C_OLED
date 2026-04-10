#include <driverlib.h>
#include "MyI2C.h"
#include "OLED.h"
#include "Delay.h"

int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;
    PM5CTL0 &= ~ LOCKLPM5;

    uint8_t num;
    
    OLED_Init();

    //Delay_ms(1000);
    OLED_ShowChar(0, 0, '#', OLED_8X16);
    OLED_ShowString(0, 16, "HELLO", OLED_8X16);
    OLED_ShowNum(0, 32, 12345, 5, OLED_8X16);
    OLED_ShowSignedNum(0, 48, -88, 2, OLED_8X16);
    //OLED_ShowHexNum(64, 32, 333, 4, OLED_8X16);
    OLED_ShowBinNum(64, 0, 333, 9, OLED_8X16);
    OLED_ShowFloatNum(64, 16, -33.15, 2, 2, OLED_8X16);
    OLED_ShowChinese(64, 32, "你好");
    OLED_Printf(64, 48, OLED_8X16, "Num:%d", num);
    OLED_Update();
    
    while(1)
    {

    }
}
