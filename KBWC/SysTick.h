// SysTick.h
// Runs on TM4C123
// Solution for CECE346 Project 3.
// Provide functions that initialize the SysTick module and generate 
// specified number of machine cycles delay using busy waiting approach
// by Min He, 7/20/2024

#include <stdint.h>

// Initialize SysTick with core clock.
void SysTick_Init(void);

// Time delay using busy wait.
// The delay parameter is in units of the core clock:1/16MHz 
void SysTick_Wait(uint32_t delay);

