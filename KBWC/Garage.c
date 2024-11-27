// Garage.c
// Runs on TM4C123
// Solution for CECE346 Project 3.
// by Min He, 7/20/2024

// PD0 connected to driver for stepper motor coil A/In1
// PD1 connected to driver for stepper motor coil A'/In2
// PD2 connected to driver for stepper motor coil B/In3
// PD3 connected to driver for stepper motor coil B'/In4
// PD6 connected to IR sesnsor output

#include "tm4c123gh6pm.h"
#include "Garage.h"
#include <stdint.h>
#include "SysTick.h"

// TODO: bit address definitions for stepper motor interface and three onboard LEDs
#define STEPPER  (*((volatile uint32_t *)0))  // PORT D, pin: 0,1,2,3, used to control garage door
#define LED      (*((volatile uint32_t *)0))  // PORTF, pin: 1,2,3

// TODO: define value for the three onboard LEDs
#define GREEN 					(0)  // PF3 connects to green LED
#define RED 						(0)  // PF1 connects to red LED
#define BLUE 						(0)  // PF2 connects to blue LED

struct State{
  uint8_t Out;     // Output
  uint8_t Next[2]; // CW/CCW Next[0]->CW, Next[1]->CCW
};
typedef const struct State StateType;

enum Stepper_Dir {CLOCKWISE, COUNTERCLOCKWISE};
enum FSM_STATES {STEP1,STEP2,STEP3,STEP4}; 

// TODO: constant definitions
#define DEGREE_HUNDRED_STEPS 		18  // each step moves 0.18 degree, 100 steps moves 18 degree
#define HALF_SEC      		500*T1ms 	//systick reload value for 0.5s
#define T1ms 							16000UL    // Systick reload value to generate 1ms delay, assumes using 16 MHz Clock.
#define CURRENT_SPEED 		STANDARD_SPEED  	// fastest speed the stepper can move
#define HIGHEST_SPEED 		2*T1ms  	// fastest speed the stepper can move
#define FASTER_SPEED			5*T1ms
#define STANDARD_SPEED		10*T1ms  	// stepper motor speed: output every 10ms, frequency for the stepper motor is 100Hz.
#define GARAGE_STEPS      (0UL)     // number of steps to fully open/close the garage door
#define STEPPER_MASK  		(0)       // bit positions for stepper motor: PD3-0
#define HALF_S_COUNT			(0UL)     // number of stepper motor steps to generate 0.5s. Ex: HALF_SEC/CURRENT_SPEED = 50
#define PORTF_PRI_BITS 	  (0)
#define PORTF_INT_PRI     (0)

StateType fsm[4]={
	// index 0: state 0,state goes from 0 to 3,  output 1100,
	// if next state index is 0: move clockwise, next state for clockwise movement is 1
	// CW state transition is: 0->1->2->3 then repeat, output transition: 3->6->12->9
	// CCW state transition is: 0->3->2->1 then repeat, output transition: 3->9->12->6
};

// Move clockwise, speed is controlled by the systick reload value 
// each step moves 0.18 degree: each 100 steps move 18 degree.
// GARAGE_STEPS determines degrees to open/close the garage door.
// Flash LED here every 0.5 second.
void Open_Garage(void){
  uint8_t s=STEP1; // current state
	uint32_t i,n=(100*GARAGE_STEPS)/DEGREE_HUNDRED_STEPS;

	LED = RED; 
	
	// TODO: make enough steps to fully open the garage door
	// Flash red LED every 0.5 second while move the stepper motor.
	
	// Change LED color to indicate the garage door is fully opened
	LED = BLUE;
	
	// wait half second after the garage door is fully opened.
  SysTick_Wait(HALF_SEC);	
}

// Move counterclockwise, speed is the systick reload value to control time to wait after each step
// Each step moves 0.18 degree: one complete circle is 360 degrees
void Close_Garage(void){
  uint8_t s=STEP1; // current state
	uint16_t i,n=(100*GARAGE_STEPS)/DEGREE_HUNDRED_STEPS;

	LED = RED; 
	
	// TODO: make enough steps to fully open the garage door
	// Flash red LED every 0.5 second while move the stepper motor.
	
	// Change LED color to indicate the garage door is fully closed
	LED = GREEN;
	
	// wait half second after the garage door is fully closed.
  SysTick_Wait(HALF_SEC);	
}

// Initialize Stepper interface: including
// Four pins to drive the stepper motor driver
// One pin to collect information from the sensor: enable both edge interrupt for this pin.
void Stepper_Sensor_Init(void){
}

// Initialize PORTF for three LEDs and two switches.
// Enable interrupt for sw1 & sw2
// Initialize LED to red.
void SwLed_Init(void){
}

void Garage_Init(void) {
	Stepper_Sensor_Init();
	SwLed_Init();
}

