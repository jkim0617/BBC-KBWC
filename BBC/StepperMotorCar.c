// StepperMotorCar.c
// Runs on TM4C123
// Test the functions provided by Stepper.c,
// 
// Before connecting a real stepper motor, remember to put the
// proper amount of delay between each CW() or CCW() step.
// Daniel Valvano
// September 12, 2013
// Modified by Min HE

// Left stepper motor connections
// PD0 connected to driver for stepper motor coil A/In1
// PD1 connected to driver for stepper motor coil A'/In2
// PD2 connected to driver for stepper motor coil B/In3
// PD3 connected to driver for stepper motor coil B'/In4

// right stepper motor connections
// PE0 connected to driver for stepper motor coil A/In1
// PE1 connected to driver for stepper motor coil A'/In2
// PE2 connected to driver for stepper motor coil B/In3
// PE3 connected to driver for stepper motor coil B'/In4
#include <stdint.h>
#include "Stepper.h"
#include "Systick.h"

#define T1ms 							16000U    // Systick reload value to generate 1ms delay, assumes using 16 MHz Clock.
#define HIGHEST_SPEED 		2*T1ms  // fastest speed the stepper can move
#define FASTER_SPEED			5*T1ms
#define STANDARD_SPEED		10*T1ms  // stepper motor speed: output every 10ms, frequency for the stepper motor is 100Hz.
#define HALF_SEC      		500*T1ms //systick reload value for 0.5s

int main(void){
	uint16_t i=0;
	
  Stepper_Init();
  SysTick_Init();
	
  while(1){
    Step_Forward(STANDARD_SPEED,180);   
		Stop_Car();
	  SysTick_Wait(HALF_SEC);  // wait for 0.5s
		
		// car turn left 90 degrees: left wheel move backward, right wheel move forward
    Step_Left(STANDARD_SPEED,90);   
		Stop_Car();
	  SysTick_Wait(HALF_SEC);  // wait for 0.5s
		
		// car move backward 180 degrees
    Step_Backward(STANDARD_SPEED,180);   
		Stop_Car();
	  SysTick_Wait(HALF_SEC);  // wait for 0.5s
	
		// car turn right 90 degrees: left wheel move forward, right wheel move backward
    Step_Right(STANDARD_SPEED,90);  
		Stop_Car();
	  SysTick_Wait(HALF_SEC);  // wait for 0.5s
  }
}
