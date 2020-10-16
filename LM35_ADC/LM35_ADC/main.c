/*
 * LM35_ADC.c
 *
 * Created: 10/16/2020 12:11:32 PM
 * Author : QuiBui - HCMUT
 */ 

#include "ADC.h"
#include "LCD.h"

int main(void)
{
    char Temperature[10];
	float Cencius;
	
	LCD_Init();
	ADC_Init();
	
    while (1) 
    {
		LCD_String_xy(1, 0, "Temperature:");
		Cencius = ADC_Read(0) * 4.88;
		Cencius = Cencius / 10;
		sprintf(Temperature, "%d%cC", (int) Cencius, DEGREE_SYMBOL); // Convert Integer value to ASCII string
		LCD_String_xy(2, 0, Temperature);
		_delay_ms(1000);
		
    }
}

