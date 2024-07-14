/* 
 * File:   ECU_layer_init.h
 * Author: En.Ahmed
 *
 * Created on April 17, 2024, 12:35 AM
 */

#ifndef ECU_LAYER_INIT_H
#define	ECU_LAYER_INIT_H
/*  section  : includes  */
#include"Led/ecu_Led.h"
#include"button/ecu_button.h"
#include"Relay/ECU_Realy.h"
#include"DC_motor/ECU_DC_MOTOR.h"
#include"Seven_Segment/Seven_Segment.h"
#include"Key_pad/ECU_key_pad.h"
#include"Chr_LCD/ECU_Char_LCD.h"
/*section  : Macro Declarations */

/*section  : Macro function Declarations */


/*section  : Data Type Declarations  */
extern chr_lcd_4bit_t lcd;
extern keypad_t keypad;
extern dc_motor_t Motor;
extern led_t Led_UnLocked;
extern led_t Led_Locked;
/*section  : function Declarations  */
void ecu_layer_initialize();

#endif	/* ECU_LAYER_INIT_H */

