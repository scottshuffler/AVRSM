#include "../kernel-land/kernel.h"
#include "DHT22.h"
#include "w5100.h"
int main(void)
{
	serial_open(19200, SERIAL_8N1);
    while(1)
    {
        //prints(" $$$$$$$$ ");
        _delay_ms(800);
        //getTempHumidity();
        //prints((uint8_t*)TOTAL_RAM_SIZE);
        char buffer[16];
        sprintf(buffer,"%d",(int)TOTAL_RAM_SIZE);
        prints(buffer);
        //kn_create_thread(THREAD1, &threadB, false, NULL);
        // get_temp();
        // _delay_ms(800);
    }
}