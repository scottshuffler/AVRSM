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
#include <stdbool.h>
#include "../user-land/main.h"
bool (*fun)();
typedef unsigned int (*f)();
f thread_ptr[8];

int func_yield[8];


int kn_create_thread(f thread);
void kn_run_thread(int count);
void init_yield_array();
void yield();

#endif /* KERNEL_H_ */