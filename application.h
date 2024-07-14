/* 
 * File:   application.h
 * Author: En.Ahmed
 *
 * Created on March 4, 2024, 7:46 PM
 */

#ifndef APPLICATION_H
#define	APPLICATION_H

/*  section  : includes  */
#include"ECU_Layer/ECU_layer_init.h"
#include"MCAL_Layer/interrupt/mcal_external_interrupt.h"
#include"MCAL_Layer/EEPROM/hal_eeprom.h"
#include"MCAL_Layer/ADC/hal_adc.h"
#include"MCAL_Layer/Timer0/hal_timer0.h"
#include"MCAL_Layer/Timer1/hal_timer1.h"
#include"MCAL_Layer/Timer2/hal_timer2.h"
#include"MCAL_Layer/Timer3/hal_timer3.h"
#include"MCAL_Layer/CCP1/hal_ccp1.h"
#include"MCAL_Layer/usart/hal_usart.h"
#include"MCAL_Layer/SPI/HAL_SPI.h"
#include"MCAL_Layer/I2C/HAL_I2C.h"
/*section  : Macro Declarations */
#define _XTAL_FREQ  4000000UL
#define DEBOUNE_TIME 200
#define ACTIVE_TIME  5000
#define DIS_ACTIVE_TIME  2500
/*section  : Macro function Declarations */


/*section  : Data Type Declarations  */

/*section  : function Declarations  */
void application_initialize(void);
uint8 keypad_read_value();
void Clear_Lcd();
void Unlocked_Led_On();
void Unlocked_Led_Off();
void Motor_Right();
void Motor_Left();
void Motor_Stop();
void locked_Led_Off();
void locked_Led_On();
#endif	/* APPLICATION_H */

