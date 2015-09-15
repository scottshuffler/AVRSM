#include "../kernel-land/kernel.h"
#include "DHT22.h"
int main(void)
{
	serial_open(19200, SERIAL_8N1);
    while(1)
    {
        prints(" $$$$$$$$ ");
        _delay_ms(800);
        getTempHumidity();
        // get_temp();
        // _delay_ms(800);
    }
}