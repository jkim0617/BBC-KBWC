// Stepper.c
// Runs on TM4C123
// Provide functions that step the motor once clockwise, step
// once counterclockwise, and initialize the stepper motor
// interface.
// Daniel Valvano
// September 12, 2013
// Modified by Dr. Min He April 28, 2017

// PD3 connected to driver for stepper motor coil A
// PD2 connected to driver for stepper motor coil A'
// PD1 connected to driver for stepper motor coil B
// PD0 connected to driver for stepper motor coil B'

#include <stdint.h>
#include "tm4c123gh6pm.h"
#include "Systick.h"

struct State{
  uint8_t Left;     // Output
  uint8_t Right;     // Output
  uint8_t Next[2]; // CW/CCW Next[0]->CW, Next[1]->CCW
};
typedef const struct State StateType;

// TODO: finish the following constant definitions
//#define FORWARD ?        // Next index
//#define BACKWARD ?       // Next index
//#define HUNDRED_STEPS ?       // each step moves 0.18 degree, 100 steps moves 18 degree

enum states {S0, S1, S2, S3};

// TODO: finish the FSM definition
StateType fsm[4]={
	// index 0: state 0,state goes from 0 to 3,
	// to move forward: PD3-0:left CCW; PE3-0,right CW
	// CW state transition is: 3->6->12->9 then repeat
	// CCW state transition is: 3->9->12->6 then repeat
};

uint8_t s, l_s, r_s; // current state

// TODO: define bit addresses for stepper motor pins
//#define LEFT_STEPPER  (*((volatile uint32_t *)?))  // PORT D, pin: 0,1,2,3
//#define RIGHT_STEPPER  (*((volatile uint32_t *)?))  // PORT E, pin: 0,1,2,3

// stop the stepper motor car and reset FSM states
void Stop_Car(void) {
}

// Move forward, speed is the systick reload value to control time to wait after each step
// each step moves 0.18 degree: one complete circle is 360 degrees
void Step_Forward(uint32_t speed, uint16_t degree){
}

// Move backward, speed is the systick reload value to control time to wait after each step
// each step moves 0.18 degree: one complete circle is 360 degrees
void Step_Backward(uint32_t speed, uint16_t degree){
}

// car turn right: left wheel move forward(CCW), right wheel move backward(CCW)
void Step_Right(uint32_t speed, uint16_t degree){	
}

// car turn left: left wheel move backward(CW), right wheel move forward(CW)
void Step_Left(uint32_t speed, uint16_t degree){	
}

// Initialize left Stepper motor interface
void Stepper_Init(void){
}
