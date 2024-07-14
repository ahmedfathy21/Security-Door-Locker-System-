/* 
 * File:   ECU_key_pad.h
 * Author: En.Ahmed
 *
 * Created on April 16, 2024, 3:10 PM
 */

#ifndef ECU_KEY_PAD_H
#define	ECU_KEY_PAD_H
/*  section  : includes  */
#include"ECU_Key_pad_cfg.h"
#include"../../MCAL_Layer/GPIO/hal_gpio.h"
/*section  : Macro Declarations */
#define ECU_KEYPAD_ROW     4
#define ECU_KEYPAD_COLUMNS  4



/*section  : Macro function Declarations */


/*section  : Data Type Declarations  */
typedef struct{
    pin_config_t keypad_row_pins[ECU_KEYPAD_ROW];
    pin_config_t keypad_coulmn_pins[ECU_KEYPAD_COLUMNS];
}keypad_t;

/*section  : function Declarations  */
std_ReturnType keypad_initialize(const keypad_t* keypad);
std_ReturnType keypad_get_value(const keypad_t* keypad,uint8 *value);

#endif	/* ECU_KEY_PAD_H */

