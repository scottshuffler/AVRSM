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
#include <avr/pgmspace.h>
#include <util/atomic.h>


// void start_thread();
// void sleep();
// void suspend_thread();
// void resume_thread();

int curr_thread = 0;
static int thread_count = 0;

int kn_create_thread(f thread) {

	if (thread_count >= MAX_NUM_THREADS) {
		prints("Cannot create more than 8 threads!\n");
	}
	else {
		thread_ptr[thread_count] = *thread;
		
		// char buffer[16];
  		// sprintf(buffer,"%d",(int)thread_ptr[thread_count]);
  		// prints(buffer);
        thread_count++;
        return thread_count - 1;
	}
}

void kn_run_thread(int thread) {
	if (!func_yield[thread]) {
		curr_thread = thread;
		fun = thread_ptr[thread];
		fun();
		// char buffer[16];
  		// sprintf(buffer,"%d",(int)thread_ptr[0]);
  		// prints(buffer);
	}
	// else {
	// 	prints(" Yeilding ");
	// }
}

void init_yield_array() {
	int i;
	for (i = 0; i < MAX_NUM_THREADS; i++) {
		func_yield[i] = 0;
	}
}

void yield() {
	func_yield[curr_thread] = 1;
	if(curr_thread+1 == thread_count) {
		func_yield[0] = 0;
	}
	else {
		func_yield[curr_thread+1] = 0;
	}
}

/**
 * @brief [brief description]
 * @details [long description]
 */
void timer1_init()
{
    TCCR1B |= (1 << WGM12) | (1 << CS11);
    TCNT1 = 0;
    OCR1AH = (TIMER_VALUE >> 8);
    OCR1AL = TIMER_VALUE;
    TIMSK1 |= (1 << OCIE1A);
    sei();
}

/**
 * @brief [brief description]
 * @details [long description]
 * 
 * @param  [description]
 */
ISR(TIMER1_COMPA_vect)
{
    millis++;
}

/**
 * @brief [brief description]
 * @details [long description]
 * @return [description]
 */
unsigned long long getMS ()
{
    unsigned long long ms;
    ATOMIC_BLOCK(ATOMIC_FORCEON) {
        ms = millis;
    }
    return ms;
}


