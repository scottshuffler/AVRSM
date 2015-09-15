#include "serial.h"

void serial_open(long speed, int config)
{
	//Switch for baud rate
	//Uses table from the data sheet
	//Sets U2X0 to 1 or 0 depending on which has a lower % error
	switch (speed)
	{
		case 2400:
		UBRR0 = 832;
		UCSR0A |= (1<<U2X0);
		break;
		case 4800:
		UBRR0 = 207;
		UCSR0A &= ~(1<<U2X0);
		break;
		case 9600:
		UBRR0 = 103;
		UCSR0A &= ~(1<<U2X0);
		break;
		case 14400:
		UBRR0 = 68;
		UCSR0A &= ~(1<<U2X0);
		break;
		case 19200:
		UBRR0 = 51;
		UCSR0A &= ~(1<<U2X0);
		break;
		case 28800:
		UBRR0 = 68;
		UCSR0A |= (1<<U2X0);
		break;
		case 38400:
		UBRR0 = 25;
		UCSR0A &= ~(1<<U2X0);
		break;
		case 57600:
		UBRR0 = 16;
		UCSR0A &= ~(1<<U2X0);
		break;
		case 76800:
		UBRR0 = 12;
		UCSR0A &= ~(1<<U2X0);
		break;
		case 115200:
		UBRR0 = 16;
		UCSR0A |= (1<<U2X0);
		break;
		case 230400:
		UBRR0 = 3;
		UCSR0A &= ~(1<<U2X0);
		break;
		case 250000:
		UBRR0 = 3;
		UCSR0A &= ~(1<<U2X0);
		break;
		default:
		return;
	}
	
	//Switch for the configuration
	//Defaults to 8N1 if a valid choice was not entered
	//Sets certain bits on or off
	//                      UCSR0C
	//   7       6      5     4     3      2      1     0
	//UMSEL01-UMSEL00-UPM01-UPM00-USBS0-UCSZ01-UCSZ00-UCPOL0
	// Synch   Synch   Par   Par  Stop   Data   Data  Data
	switch (config)
	{
		case SERIAL_5N1:
		UCSR0C = UCSR0C & 00000000;
		break;
		case SERIAL_6N1:
		UCSR0C |= (1<<UCPOL0);
		break;
		case SERIAL_7N1:
		UCSR0C |= (1<<UCSZ00);
		break;
		case SERIAL_8N1:
		UCSR0C &= (3<<UCSZ00);
		break;
		case SERIAL_5N2:
		UCSR0C |= (1<<USBS0);
		break;
		case SERIAL_6N2:
		UCSR0C |= (1<<USBS0) | (1<<UCPOL0);
		break;
		case SERIAL_7N2:
		UCSR0C |= (1<<USBS0) | (1<<UCSZ00);
		break;
		case SERIAL_8N2:
		UCSR0C |= (1<<USBS0) | (3<<UCSZ00);
		break;
		case SERIAL_5E1:
		UCSR0C |= (1<<UMSEL00);
		break;
		case SERIAL_6E1:
		UCSR0C |= (1<<UMSEL00) | (1<<UCPOL0);
		break;
		case SERIAL_7E1:
		UCSR0C |= (1<<UMSEL00) | (1<<UCSZ00);
		break;
		case SERIAL_8E1:
		UCSR0C |= (1<<UMSEL00) | (3<<UCSZ00);
		break;
		case SERIAL_5E2:
		UCSR0C |= (1<<UMSEL00) | (1<<USBS0);
		break;
		case SERIAL_6E2:
		UCSR0C |= (1<<UMSEL00) | (1<<USBS0) | (1<<UCPOL0);
		break;
		case SERIAL_7E2:
		UCSR0C |= (1<<UMSEL00) | (1<<USBS0) | (1<<UCSZ00);
		break;
		case SERIAL_8E2:
		UCSR0C |= (1<<UMSEL00) | (1<<USBS0) | (3<<UCSZ00);
		break;
		case SERIAL_5O1:
		UCSR0C |= (3<<UMSEL00);
		break;
		case SERIAL_6O1:
		UCSR0C |= (3<<UMSEL00) | (1<<UCPOL0);
		break;
		case SERIAL_7O1:
		UCSR0C |= (3<<UMSEL00) | (1<<UCSZ00);
		break;
		case SERIAL_8O1:
		UCSR0C |= (3<<UMSEL00) | (3<<UCSZ00);
		break;
		case SERIAL_5O2:
		UCSR0C |= (3<<UMSEL00) | (1<<USBS0);
		break;
		case SERIAL_6O2:
		UCSR0C |= (3<<UMSEL00) | (1<<USBS0) | (1<<UCPOL0);
		break;
		case SERIAL_7O2:
		UCSR0C |= (3<<UMSEL00) | (1<<USBS0) | (1<<UCSZ00);
		break;
		case SERIAL_8O2:
		UCSR0C |= (3<<UMSEL00) | (1<<USBS0) | (3<<UCSZ00);
		break;
		default:
		UCSR0C &= (3<<UCSZ00);
	}
	
	
	//Set UBRRH to the highest 4 bits
	UBRR0H = (UBRR0 >> 8);
	//Set UBRRL to the rest
	UBRR0L =  UBRR0;
	//Enables TX and RX
	UCSR0B = (1 << TXEN0) | (1 << RXEN0);
	
}

void printOut(char data)
{
	while(!((UCSR0A) & (1<<UDRE0)))
	{
		;
	}
	UDR0 = data;
}

void prints(char* data)
{
	while(*data)
	{
		printOut(*data++);
	}
}

