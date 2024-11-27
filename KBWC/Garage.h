// Garage.h
// Runs on TM4C123
// Solution for CECE346 Project 3.
// by Min He, 7/20/2024

#include <stdint.h>

// Sensor port defenition
#define SENSOR 						(*((volatile uint32_t *)0x40007100)) // PD6
#define SENSOR_MASK  			0x40  // bit position for SENSOR: PD6
#define SW1_MASK  			0x10  // bit position for switch1: PF4
#define SW2_MASK  			0x01  // bit position for switch2: PF0

// Initialize Stepper interface
void Garage_Init(void);
void Open_Garage(void);
void Close_Garage(void);
