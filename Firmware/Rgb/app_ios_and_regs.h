#ifndef _APP_IOS_AND_REGS_H_
#define _APP_IOS_AND_REGS_H_
#include "cpu.h"

void init_ios(void);
/************************************************************************/
/* Definition of input pins                                             */
/************************************************************************/
// DI0                    Description: Input DIO
// LEDS_READY0            Description: High when have array loaded until update the RGBs
// LEDS_READY1            Description: High when have array loaded until update the RGBs
// DISABLING_LEDS0        Description: High while turning off the RGBs
// DISABLING_LEDS1        Description: High while turning off the RGBs

#define read_DI0 read_io(PORTA, 0)              // DI0
#define read_LEDS_READY0 read_io(PORTB, 1)      // LEDS_READY0
#define read_LEDS_READY1 read_io(PORTC, 6)      // LEDS_READY1
#define read_DISABLING_LEDS0 read_io(PORTB, 2)  // DISABLING_LEDS0
#define read_DISABLING_LEDS1 read_io(PORTC, 7)  // DISABLING_LEDS1

/************************************************************************/
/* Definition of output pins                                            */
/************************************************************************/
// DO0                    Description: Output DO0
// DO1                    Description: Output DO1
// DO2                    Description: Output DO2
// DO3                    Description: Output DO3
// DO4                    Description: Output DO4
// UPDATE_LEDS0           Description: Update the RGBs on Bus 0
// DISABLE_LEDS0          Description: Turn OFF the RGBs on Bus 0
// UPDATE_LEDS1           Description: Update the RGBs on Bus 1
// DISABLE_LEDS1          Description: Turn OFF the RGBs on Bus 1
// DEMO_MODE0             Description: Enable demonstration mode on Bus 0
// DEMO_MODE1             Description: Enable demonstration mode on Bus 1

/* DO0 */
#define set_DO0 set_io(PORTA, 1)
#define clr_DO0 clear_io(PORTA, 1)
#define tgl_DO0 toggle_io(PORTA, 1)
#define read_DO0 read_io(PORTA, 1)

/* DO1 */
#define set_DO1 set_io(PORTA, 2)
#define clr_DO1 clear_io(PORTA, 2)
#define tgl_DO1 toggle_io(PORTA, 2)
#define read_DO1 read_io(PORTA, 2)

/* DO2 */
#define set_DO2 set_io(PORTA, 3)
#define clr_DO2 clear_io(PORTA, 3)
#define tgl_DO2 toggle_io(PORTA, 3)
#define read_DO2 read_io(PORTA, 3)

/* DO3 */
#define set_DO3 set_io(PORTA, 4)
#define clr_DO3 clear_io(PORTA, 4)
#define tgl_DO3 toggle_io(PORTA, 4)
#define read_DO3 read_io(PORTA, 4)

/* DO4 */
#define set_DO4 set_io(PORTA, 5)
#define clr_DO4 clear_io(PORTA, 5)
#define tgl_DO4 toggle_io(PORTA, 5)
#define read_DO4 read_io(PORTA, 5)

/* UPDATE_LEDS0 */
#define set_UPDATE_LEDS0 set_io(PORTA, 6)
#define clr_UPDATE_LEDS0 clear_io(PORTA, 6)
#define tgl_UPDATE_LEDS0 toggle_io(PORTA, 6)
#define read_UPDATE_LEDS0 read_io(PORTA, 6)

/* DISABLE_LEDS0 */
#define set_DISABLE_LEDS0 set_io(PORTA, 7)
#define clr_DISABLE_LEDS0 clear_io(PORTA, 7)
#define tgl_DISABLE_LEDS0 toggle_io(PORTA, 7)
#define read_DISABLE_LEDS0 read_io(PORTA, 7)

/* UPDATE_LEDS1 */
#define set_UPDATE_LEDS1 set_io(PORTC, 3)
#define clr_UPDATE_LEDS1 clear_io(PORTC, 3)
#define tgl_UPDATE_LEDS1 toggle_io(PORTC, 3)
#define read_UPDATE_LEDS1 read_io(PORTC, 3)

/* DISABLE_LEDS1 */
#define set_DISABLE_LEDS1 set_io(PORTC, 4)
#define clr_DISABLE_LEDS1 clear_io(PORTC, 4)
#define tgl_DISABLE_LEDS1 toggle_io(PORTC, 4)
#define read_DISABLE_LEDS1 read_io(PORTC, 4)

/* DEMO_MODE0 */
#define set_DEMO_MODE0 set_io(PORTB, 0)
#define clr_DEMO_MODE0 clear_io(PORTB, 0)
#define tgl_DEMO_MODE0 toggle_io(PORTB, 0)
#define read_DEMO_MODE0 read_io(PORTB, 0)

/* DEMO_MODE1 */
#define set_DEMO_MODE1 set_io(PORTC, 5)
#define clr_DEMO_MODE1 clear_io(PORTC, 5)
#define tgl_DEMO_MODE1 toggle_io(PORTC, 5)
#define read_DEMO_MODE1 read_io(PORTC, 5)


/************************************************************************/
/* Registers' structure                                                 */
/************************************************************************/
typedef struct
{
	uint8_t REG_LEDS_STATUS;
	uint8_t REG_LEDS_ON_BUS;
	uint8_t REG_COLOR_ARRAY[192];
	uint8_t REG_COLOR_ARRAY_BUS0[96];
	uint8_t REG_COLOR_ARRAY_BUS1[96];
	uint8_t REG_RESERVED0;
	uint8_t REG_RESERVED1;
	uint8_t REG_DI0_CONF;
	uint8_t REG_DO0_CONF;
	uint8_t REG_DO1_CONF;
	uint8_t REG_RESERVED2;
	uint8_t REG_RESERVED3;
	uint8_t REG_INPUTS_STATE;
	uint8_t REG_OUTPUTS_SET;
	uint8_t REG_OUTPUTS_CLEAR;
	uint8_t REG_OUTPUTS_TOGGLE;
	uint8_t REG_OUTPUTS_OUT;
	uint8_t REG_RESERVED4;
	uint8_t REG_RESERVED5;
	uint8_t REG_EVNT_ENABLE;
} AppRegs;

/************************************************************************/
/* Registers' address                                                   */
/************************************************************************/
/* Registers */
#define ADD_REG_LEDS_STATUS                 32 // U8     Writing any value above ZERO will start the acquisition. ZERO will stop it.
#define ADD_REG_LEDS_ON_BUS                 33 // U8     Number of RGB LEDs used (half on each bus) (Max. is 64)
#define ADD_REG_COLOR_ARRAY                 34 // U8     RGBs' values on the format R G B
#define ADD_REG_COLOR_ARRAY_BUS0            35 // U8     RGBs' values for the bus 0 on the format R G B
#define ADD_REG_COLOR_ARRAY_BUS1            36 // U8     RGBs' values for the bus 1 on the format R G B
#define ADD_REG_RESERVED0                   37 // U8     
#define ADD_REG_RESERVED1                   38 // U8     
#define ADD_REG_DI0_CONF                    39 // U8     Configuration of the digital input 0 (DI0)
#define ADD_REG_DO0_CONF                    40 // U8     Configuration of the digital output 0 (DO0)
#define ADD_REG_DO1_CONF                    41 // U8     Configuration of the digital output 1 (DO1)
#define ADD_REG_RESERVED2                   42 // U8     
#define ADD_REG_RESERVED3                   43 // U8     
#define ADD_REG_INPUTS_STATE                44 // U8     Read the correspondent input pin
#define ADD_REG_OUTPUTS_SET                 45 // U8     Set the correspondent output
#define ADD_REG_OUTPUTS_CLEAR               46 // U8     Clear the correspondent output
#define ADD_REG_OUTPUTS_TOGGLE              47 // U8     Toggle the correspondent output
#define ADD_REG_OUTPUTS_OUT                 48 // U8     Control the correspondent output
#define ADD_REG_RESERVED4                   49 // U8     
#define ADD_REG_RESERVED5                   50 // U8     
#define ADD_REG_EVNT_ENABLE                 51 // U8     Enable the Events

/************************************************************************/
/* PWM Generator registers' memory limits                               */
/*                                                                      */
/* DON'T change the APP_REGS_ADD_MIN value !!!                          */
/* DON'T change these names !!!                                         */
/************************************************************************/
/* Memory limits */
#define APP_REGS_ADD_MIN                    0x20
#define APP_REGS_ADD_MAX                    0x33
#define APP_NBYTES_OF_REG_BANK              401

/************************************************************************/
/* Registers' bits                                                      */
/************************************************************************/
#define B_RGBS_UPDATED                     (1<<0)       // RGBs were updated if 1 or disabled if 0
#define MSK_DI0_SEL                        (3<<0)       // 
#define GM_DI0_SYNC                        (0<<0)       // Use as a pure digital input
#define GM_DI0_RISE_UPDATE_RGBS            (1<<0)       // Update RGBs with a rising edge
#define GM_DI0_HIGH_RGBS_ON                (2<<0)       // Turn RGBs ON when pin is at logic high
#define MSK_DO_SEL                         (3<<0)       // 
#define GM_DO_DIG                          (0<<0)       // Use as a pure digital output
#define GM_DO_PULSE_WHEN_UPDATED           (1<<0)       // Pulse 1 ms when the RGBs are updated
#define GM_DO_PULSE _WHEN_ARRAY_LOADED     (2<<0)       // Pulse 1 ms when a new color array is loaded
#define B_DI0                              (1<<0)       // 
#define B_DO0                              (1<<0)       // 
#define B_DO1                              (1<<1)       // 
#define B_DO2                              (1<<2)       // 
#define B_DO3                              (1<<3)       // 
#define B_DO4                              (1<<3)       // 
#define B_EVT_LED_STATUS                   (1<<0)       // Event of register EVT_LED_STATUS
#define B_EVT_INPUTS_STATE                 (1<<1)       // Event of register EVT_INPUTS_STATE

#endif /* _APP_REGS_H_ */