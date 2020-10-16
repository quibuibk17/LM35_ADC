/*
 * ADC.h
 *
 * Created: 10/16/2020 1:18:25 PM
 *  Author: Admin
 */ 


#ifndef ADC_H_
#define ADC_H_

#define F_CPU 16000000UL
#include <avr/io.h>
#include <string.h>
#include <stdio.h>
#include <util/delay.h>

#define DEGREE_SYMBOL 0XDF

#define ADC_Port DDRA
#define ADC_Channel 0

void ADC_Init();
int ADC_Read(char);


#endif /* ADC_H_ */