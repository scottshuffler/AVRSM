/*
 * main.c
 *
 * Created: 8/17/2015 5:14:53 PM
 *  Author: shuffleres
 */ 
#include <avr/io.h>
#include "kernel.h"
#include <util/delay.h>
#include <avr/interrupt.h>

void create_thread();
void start_thread();
void sleep();
void suspend_thread();
void resume_thread();


// int main(void)
// {
// 	serial_open(19200, SERIAL_8N1);
//     while(1)
//     {
//         prints(" ###### ");
//         // _delay_ms(800);
//         // get_temp();
//         // _delay_ms(800);
//     }
// }

// void get_temp() {
// 	cli();
	
// 	pinMode(7,OUTPUT);
// 	digitalWrite(7,LOW);
//     _delay_us(480);

// 	pinMode(7,INPUT_PULLUP);
// 	digitalWrite(7,HIGH);
// 	_delay_us(75);
// 	if(digitalRead(7))
// 	{
// 		prints("\nNo response from sensor, check connection\n");
// 	}
// 	else
// 	{
// 		prints("\nGot a response\n");
// 	}
// 	while(!digitalRead(7)) {
// 		prints("\nLow\n");
// 		_delay_us(1);
// 	}
// 	prints("\nHigh\n");

// }

//Selects which mode to set a pin to.
//Tests to see if the pin and mode is in bounds
// void pinMode(int pin, char mode)
// {
// 	if (pin > 53 || pin < 0)
// 	{
// 		return -1;
// 	}
// 	if (mode < 0 || mode > 2)
// 	{
// 		return -1;
// 	}
// 	//Input
// 	if (mode == 0)
// 	{
// 		*(map[pin].ddr) &= ~(1 << map[pin].bitShift);
// 		*(map[pin].ddr + 1) &= ~(1 << map[pin].bitShift);
// 	}
// 	//Output
// 	else if (mode == 1)
// 	{
// 		*(map[pin].ddr) |= (1 << map[pin].bitShift);
// 	}
// 	//Pullup
// 	else if(mode == 2)
// 	{
// 		*(map[pin].ddr) &= ~(1 << map[pin].bitShift);
// 		*(map[pin].ddr + 1) |= (1 << map[pin].bitShift);
// 	}
	
// }

// //Tests to see if there is a voltage on the pin
// int digitalRead(int pin)
// {
// 	return (*(map[pin].ddr - 1) & (1 << map[pin].bitShift)) ? 1 : 0;

// }

// //Changes the bit to turn it on or off
// void digitalWrite(int pin, int value)
// {
// 	if (value < 0 || value > 1)
// 	{
// 		return -1;
// 	}
// 	if (value == 1)
// 	{
// 		*(map[pin].ddr + 1) |= (1 << map[pin].bitShift);
// 	}
// 	else
// 	{
// 		*(map[pin].ddr + 1) &= ~(1 << map[pin].bitShift);
// 	}
// }



// //Grab the correct bits and set them to a unsigned int value
// //That value / 10 is the temp, and that value mod 10 is the decimal
// //Then print the correct string, had to use an array of chars for printing
// //Mod and division on decimal values only
// void printTempInF(uint8_t bytes2, uint8_t bytes3)
// {
// 	char buffer[8];
// 	int temp = ((bytes2) << 8) | bytes3;
// 	temp = temp / 10;
// 	int remainder = temp % 10;
// 	//C -> F conversion
// 	temp = ((temp * 9)/5) + 32;
// 	//Check for negative
// 	if(bytes2  < 0)
// 	{
// 		temp = temp * -1;
// 	}
// 	itoa(temp,buffer,10);
// 	prints(" TMP= ");
// 	prints(buffer);
// 	itoa(remainder,buffer,10);
// 	prints(".");
// 	prints(buffer);
// 	//prints(" \n");
// }

// //Grab the correct bits and set them to a unsigned int value
// //That value / 10 is the RH, and that value mod 10 is the decimal
// //Then print the correct string, had to use an array of chars for printing
// //Mod and division on decimal values only
// void printHumidity(uint8_t bytes0, uint8_t bytes1)
// {
// 	char buffer[8];
// 	int relHum = (bytes0 << 8) | bytes1;
// 	int remainder = relHum % 10;
// 	relHum = relHum / 10;
// 	prints("RHUM= ");
// 	itoa(relHum,buffer,10);
// 	prints(buffer);
// 	itoa(remainder,buffer,10);
// 	prints(".");
// 	prints(buffer);
// 	prints(", ");
// }

// //Make a sum variable
// //Add the four other bytes and store
// //If the sum variable is equal to the byte 4 value it passes
// int checkSum()
// {
// 	unsigned char sum;
// 	sum = bytes[0] + bytes[1] + bytes[2] + bytes[3];
// 	if(bytes[4] == sum)
// 	{
// 		return 1;
// 	}
// 	return 0;
// }

// void getTempHumidity(){
// 	for (int i = 0; i < 1; i++) {
// 	cli();
// 	digitalWrite(7,LOW);
// 	pinMode(7,OUTPUT);
//     _delay_us(600);
// 	pinMode(7,INPUT_PULLUP);
// 	_delay_us(70);
// 	//Two checks to be sure the sensor is responding
// 	//If it's not it will break out of the while loop
// 	if(digitalRead(7))
// 	{
// 		prints("\nNo response from sensor, check connection\n");
// 		break;
// 	}
// 	_delay_us(80);
// 	if (!digitalRead(7))
// 	{
// 		prints("\nNo response from sensor, check connection\n");
// 		break;
// 	}
// 	//Sensor is responding so we get ready to read
// 	//We will read the 5 bytes individually (makes it easier to do the check sum later)
// 	for (uint8_t byteVal = 0; byteVal < 5; byteVal++)
// 	{
// 		getByte = 0;
// 		//Loop through all 8 bits of the byte
// 		for (uint8_t i = 0; i < 8; i++)
// 		{
// 			getByte <<= 1;
// 			//Wait for it to go back to low
// 			while(digitalRead(PIN))
// 			{
// 				;
// 			}
// 			_delay_us(5);
// 			//wait for it to go back to high
// 			while(!digitalRead(PIN))
// 			{
// 				;
// 			}
// 			//Delay to the middle point
// 			_delay_us(50);
// 			//Check if the pin is high
// 			//If it is then |= 1
// 			if(digitalRead(PIN))
// 			{
// 				getByte |= 1;
// 			}
// 		}
// 		//Set what we just calculated into the array
// 		bytes[byteVal] = getByte;
// 	}
// 	//Print data or say there was a checksum error
// 	if (checkSum())
// 	{
// 		printHumidity(bytes[0], bytes[1]);
// 		printTempInF(bytes[2], bytes[3]);
// 	}
// 	else {
// 		prints("\n checksum is not equal \n");
// 	}
// 	//Turn interrupts back on and clear all the bytes
// 	sei();
// 	int iter;
// 	for (iter = 0; iter < 5; iter++)
// 	{
// 		bytes[iter] = 0;
// 	}
// 	//Wait for a second for the next iteration
// 	//I can make this 500ms instead but I feel like it's too fast
// 	_delay_ms(400);
// }
// }

