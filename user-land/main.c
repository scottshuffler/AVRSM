#include "main.h"

int main(void)
{
    pinMode(LEDPIN,OUTPUT);
    pinMode(LEDPIN2,OUTPUT);
    cli();
    timer1_init();
	serial_open(19200, SERIAL_8N1);
    init_yield_array();
    //int t1 = kn_create_thread(tempHumidity);
    int t2 = kn_create_thread(blink);
    int t3 = kn_create_thread(blink_faster);

    while(1)
    {
        //kn_run_thread(t1);
        kn_run_thread(t2);
        kn_run_thread(t3);
        //init_yield_array();
        // if (tot_overflow >= 10) {
        //     blink();
        //     tot_overflow = 0;
        // }
        // if (tot_overflow2 >= 15) {
        //     blink_faster();
        //     tot_overflow2 = 0;
        // }
        //kn_run_thread(t1);
        //kn_run_thread(t2);
        //kn_run_thread(t3);
        //prints(" $$$$$$$$ ");
        //_delay_ms(800);
        //getTempHumidity();
        //prints((uint8_t*)TOTAL_RAM_SIZE);        
        // char buffer[16];
        // sprintf(buffer,"%d",(int)TOTAL_RAM_SIZE);
        // prints(buffer);
        //kn_create_thread(THREAD1, &threadB, false, NULL);
        // get_temp();
        // _delay_ms(800);
    }
}

/**
 * @brief [brief description]
 * @details [long description]
 */
void tempHumidity(){
    getTempHumidity();
    yield();
}

/**
 * @brief [brief description]
 * @details [long description]
 */
void blink(){
    unsigned long long ms_curr = getMS();
    if (ms_curr - ms_since > 100) {
        digitalWrite(3,!digitalRead(3));
        ms_since = ms_curr;
    }
    yield();
}

/**
 * @brief [brief description]
 * @details [long description]
 */
void blink_faster() {
    unsigned long long ms_curr = getMS();
    if (ms_curr - ms_since2 > 1000) {
        digitalWrite(2,!digitalRead(2));
        ms_since2 = ms_curr;
    }
    yield();
}



