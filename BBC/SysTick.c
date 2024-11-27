// SysTick.h
// Runs on TM4C123
// Provide functions that initialize the SysTick module and generate 
// specified number of machine cycles delay using busy waiting approach
// Min He, 4/14/2023

#include <stdint.h>
#include "tm4c123gh6pm.h"

// TODO: Initialize SysTick with core clock.
void SysTick_Init(void){
}

// TODO: 
// Time delay using busy wait.
// The delay parameter is in units of the core clock:1/16MHz 
void SysTick_Wait(uint32_t delay){
}
