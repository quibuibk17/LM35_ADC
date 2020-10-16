/*
 * ADC.c
 *
 * Created: 10/16/2020 1:19:20 PM
 *  Author: Admin
 */ 
#include "ADC.h"

void ADC_Init()
{
	ADC_Port &= ~(1 << ADC_Channel); //Set Port PA0 la input
	ADCSRA |= (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1);
	ADCSRA &= ~(1 << ADPS0); // Enable ADC, Prescale is 64 (110)
	ADMUX |= (1 << REFS0);
	ADMUX &= ~(1 << REFS1); // Select reference voltage is AVCC pin, 5V
	//ADMUX &= ~(1 << MUX4) & ~(1 << MUX3) & ~(1 << MUX2) & ~(1 << MUX1) & ~(1 << MUX0); // Select ADC channel 0
}

int ADC_Read(char channel)
{
	ADMUX |= (channel & 0x0F); // Set input channel to read
	ADCSRA |= (1 << ADSC); // ADC start
	while(!(ADCSRA & (1 << ADIF))); // Wait until the end of conversion by polling ADID bit is 1
	ADCSRA |= (1 << ADIF); // Clear interrupt flag
	_delay_ms(1);
	return ADCW;
}
