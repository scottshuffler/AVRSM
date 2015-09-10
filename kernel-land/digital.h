/*
 * Digital.h
 *
 * Created: 2/12/2015 9:45:07 AM
 *  Author: shuffleres
 */ 


#ifndef DIGITAL_H_
#define DIGITAL_H_

#include <avr/io.h>
#include <util/delay.h>

#define HIGH 0x1
#define LOW 0x0

#define INPUT 0x0
#define OUTPUT 0x1
#define INPUT_PULLUP 0x2

struct PinMap
{
	volatile unsigned char* ddr;
	char bitNum;
	char bitShift;
};

//Array of strucs of all the ports with their pin#, bit number, and port
extern struct PinMap map[];

//Prototypes
void pinMode(int,char);
int digitalRead(int);
void digitalWrite(int,int);
void delay(int i);
#endif /* DIGITAL_H_ */
