/*
 * main.h
 *
 * Created: 4/13/2015 5:27:39 PM
 *  Author: shuffleres
 */ 


#ifndef KERNEL_H_
#define KERNEL_H_


#include <avr/io.h>
#include "digital.h"
#include "serial.h"
 #include "stack.h"
#include <util/delay.h>
#include <avr/interrupt.h>
#define PIN 7
 
short int getByte;
short int bytes[5];
int time_count;
void printOut(char data);
void prints(char* data);
char * itoa(int val,char * s,int radix);
void printTempInF(uint8_t bytes2, uint8_t bytes3);
void printHumidity(uint8_t bytes0, uint8_t bytes1);
int checkSum();
void getTempHumidity();


#endif /* KERNEL_H_ */