/*
 * TempHumidity.h
 *
 * Created: 4/13/2015 5:27:39 PM
 *  Author: shuffleres
 */ 


#ifndef DHT22_H_
#define DHT22_H_


#include <avr/io.h>
#include "../kernel-land/kernel.h"
#define PIN 7
short int getByte;
short int bytes[5];
int time_count;
char * itoa(int val,char * s,int radix);
void printTempInF(uint8_t bytes2, uint8_t bytes3);
void printHumidity(uint8_t bytes0, uint8_t bytes1);
int checkSum();
int getTempHumidity(void);


#endif /* DHT22_H_ */