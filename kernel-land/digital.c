#include "digital.h"

struct PinMap map[] = {
	{ &DDRE, 0, 0},
	{ &DDRE, 1, 1},
	{ &DDRE, 2, 4},
	{ &DDRE, 3, 5},
	{ &DDRG, 4, 5},
	{ &DDRE, 5, 3},
	{ &DDRH, 6, 3},
	{ &DDRH, 7, 4},
	{ &DDRH, 8, 5},
	{ &DDRH, 9, 6},
	{ &DDRB, 10, 4},
	{ &DDRB, 11, 5},
	{ &DDRB, 12, 6},
	{ &DDRB, 13, 7},
	{ &DDRJ, 14, 1},
	{ &DDRJ, 15, 0},
	{ &DDRH, 16, 1},
	{ &DDRH, 17, 0},
	{ &DDRD, 18, 3},
	{ &DDRD, 19, 2},
	{ &DDRD, 20, 1},
	{ &DDRD, 21, 0},
	{ &DDRA, 22, 0},
	{ &DDRA, 23, 1},
	{ &DDRA, 24, 2},
	{ &DDRA, 25, 3},
	{ &DDRA, 26, 4},
	{ &DDRA, 27, 5},
	{ &DDRA, 28, 6},
	{ &DDRA, 29, 7},
	{ &DDRC, 30, 7},
	{ &DDRC, 31, 6},
	{ &DDRC, 32, 5},
	{ &DDRC, 33, 4},
	{ &DDRC, 34, 3},
	{ &DDRC, 35, 2},
	{ &DDRC, 36, 1},
	{ &DDRC, 37, 0},
	{ &DDRD, 38, 7},
	{ &DDRG, 39, 2},
	{ &DDRG, 40, 1},
	{ &DDRG, 41, 0},
	{ &DDRL, 42, 7},
	{ &DDRL, 43, 6},
	{ &DDRL, 44, 5},
	{ &DDRL, 45, 4},
	{ &DDRL, 46, 3},
	{ &DDRL, 47, 2},
	{ &DDRL, 48, 1},
	{ &DDRL, 49, 0},
	{ &DDRB, 50, 3},
	{ &DDRB, 51, 2},
	{ &DDRB, 52, 1},
	{ &DDRB, 53, 0}
};

//Selects which mode to set a pin to.
//Tests to see if the pin and mode is in bounds
void pinMode(int pin, char mode)
{
	if (pin > 53 || pin < 0)
	{
		return -1;
	}
	if (mode < 0 || mode > 2)
	{
		return -1;
	}
	//Input
	if (mode == 0)
	{
		*(map[pin].ddr) &= ~(1 << map[pin].bitShift);
		*(map[pin].ddr + 1) &= ~(1 << map[pin].bitShift);
	}
	//Output
	else if (mode == 1)
	{
		*(map[pin].ddr) |= (1 << map[pin].bitShift);
	}
	//Pullup
	else if(mode == 2)
	{
		*(map[pin].ddr) &= ~(1 << map[pin].bitShift);
		*(map[pin].ddr + 1) |= (1 << map[pin].bitShift);
	}
	
}

//Tests to see if there is a voltage on the pin
int digitalRead(int pin)
{
	return (*(map[pin].ddr - 1) & (1 << map[pin].bitShift)) ? 1 : 0;

}

//Changes the bit to turn it on or off
void digitalWrite(int pin, int value)
{
	if (value < 0 || value > 1)
	{
		return -1;
	}
	if (value == 1)
	{
		*(map[pin].ddr + 1) |= (1 << map[pin].bitShift);
	}
	else
	{
		*(map[pin].ddr + 1) &= ~(1 << map[pin].bitShift);
	}
}