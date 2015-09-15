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

void create_thread();
void start_thread();
void sleep();
void suspend_thread();
void resume_thread();


