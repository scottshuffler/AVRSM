#include "../kernel-land/kernel.h"

int main(void)
{
	serial_open(19200, SERIAL_8N1);
    while(1)
    {
        prints(" ###### ");
		char buffer[8];
        prints(buffer);
        // _delay_ms(800);
        // get_temp();
        // _delay_ms(800);
    }
}