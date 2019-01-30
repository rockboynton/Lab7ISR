/*
 * main.c
 *
 * Plays a song using piezo speaker on MSOE dev board.
 * 
 * The following menu options are implemented:
 * 				
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "uart_driver.h"
#include "led.h"
#include "lcd.h"
#include "keypad.h"
#include "delay.h"
#include "temp_sensor.h"
#include "speaker.h"

#define F_CPU 16000000UL

// 0 = main program
// 1 = Ring Buffer tests
#define DEBUG 0

// User input buffer
#define BUFFER_SIZE 30

// Initialize variables to be used 
char buffer[BUFFER_SIZE+1];

// File scope helper methods
static void print_help_screen();


// main
int main() {
	
	// Initialize hardware
	init_usart2(19200,F_CPU);
	led_init();
	lcd_init();
	key_init();
	temp_init();
	speaker_init();

	// --------------------- RING BUFFER TEST CODE -------------------
	if (DEBUG == 5) {
		char entry[20];
		while (1) {
			// TODO add tests 
		}
	}
	//-----------------------------------------------------------

	// Main program 
	// Never return
	print_help_screen();
	while (1) {
		// TODO add stuff to test functionality 
	}
	// Never returns
	return 0;
}

// No help screen neccasary
static void print_help_screen() { 
	printf("");
}


