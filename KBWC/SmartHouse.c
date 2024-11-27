// SmartHouse.c
// Runs on TM4C123
// Starter for CECE346 Project 3 Smart House with a stepper motor controlled garage door.
// by Min He, 7/20/2024

// Garage door stepper motor/sensor connections
// PD0 connected to driver for stepper motor coil A/In1
// PD1 connected to driver for stepper motor coil A'/In2
// PD2 connected to driver for stepper motor coil B/In3
// PD3 connected to driver for stepper motor coil B'/In4
// PD6 connected to IR sesnsor output

#include "tm4c123gh6pm.h"
#include <stdint.h>
#include "Garage.h"
#include "SysTick.h"
#include <stdbool.h>

extern void DisableInterrupts(void);
extern void EnableInterrupts(void);
extern void WaitForInterrupt(void);

// Constances for garage door status
enum Garage_Status {CLOSED,OPEN};
enum Garage_Status garage_status;

// Constances for car status:
// SAME means does not move across the 15cm distance.
// MOVING_OUT means moving from <15cm to >15cm
// MOVING_IN means moving from >15cm to <15cm
enum Car_Status {SAME, MOVING_OUT,MOVING_IN};

// flag shared with main() and PORTF handler
bool button_pressed = false;

int main(void){
  enum Car_Status car_status;
	
	DisableInterrupts();
  Garage_Init();
  SysTick_Init();
	garage_status = CLOSED;
	car_status = SAME;
	EnableInterrupts();
	
  while(1){	
		if (garage_status == CLOSED) {
			// If a car is moving into the garage or the gragage button (sw2) is pressed
			// open the garage door
			// reset flags: car_status, button_pressed, garage_status
			// 
			if ((car_status == MOVING_IN) | button_pressed) {
//				car_status = ?;
//		    Open_Garage();
//				button_pressed = ?;
//				garage_status = ?;
			}
		}
		else {
			// If a car is moving out of the garage or the gragage button (sw2) is pressed
			// close the garage door
			// reset flags: car_status, button_pressed, garage_status
			if ((car_status == MOVING_OUT) | button_pressed) {
//				car_status = ?;
//		    Close_Garage();
//				button_pressed = ?;
//				garage_status = ?;
			}
		}
	}
}

void GPIOPortF_Handler(void){
	// simple debouncing code: generate 20ms to 30ms delay
	for (uint32_t time=0;time<800000;time++) {}

	// take care of acknowledge and button_pressed flag here
}

void GPIOPortD_Handler(void) 
{
	// simple debouncing code: generate 20ms to 30ms delay
	for (uint32_t time=0;time<800000;time++) {}

	// take care of acknowledge and car_status flag here
}
