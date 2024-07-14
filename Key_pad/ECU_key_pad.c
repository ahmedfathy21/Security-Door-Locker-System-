/* 
 * File:   ECU_key_pad.c
 * Author: En.Ahmed
 *
 * Created on April 16, 2024, 3:10 PM
 */

#include"ECU_key_pad.h"

static const uint8 btn_values[ECU_KEYPAD_ROW][ECU_KEYPAD_COLUMNS]={
                                                                   {'7','8','9','/'},  
                                                                   {'4','5','6','*'},  
                                                                   {'1','2','3','-'},  
                                                                   {'#','0','=','+'},  
                                                                  };
/**
 * @brief initialize the assigned pin to be OUTPUT and turn the Keypad
 * @param led : pointer to the led module configurations
 * @return status of the function
 *           E_OK  : function done successfully 
 *         E_NOT_OK : the function has issue to perform this action
 */
std_ReturnType keypad_initialize(const keypad_t* keypad){
    std_ReturnType ret = E_OK ;
    uint8 l_rows_counter = ZERO_INIT,l_coulmns_counter = ZERO_INIT;
    if(keypad == NULL){
        ret = E_NOT_OK;
    }
    else 
    {
        for(l_rows_counter =ZERO_INIT;l_rows_counter<ECU_KEYPAD_ROW;l_rows_counter++){
            ret = gpio_pin_initialize(&(keypad->keypad_row_pins[l_rows_counter]));
        }
        for(l_coulmns_counter =ZERO_INIT;l_coulmns_counter<ECU_KEYPAD_COLUMNS;l_coulmns_counter++){
            ret = gpio_pin_direction_initialize(&(keypad->keypad_coulmn_pins[l_coulmns_counter]));
            
        }
    }
    return ret;
    
}

/**
 * 
 * @param keypad
 * @param value
 * @return 
 */
std_ReturnType keypad_get_value(const keypad_t* keypad,uint8 *value){
      std_ReturnType ret = E_OK ;
       
      uint8 l_rows_counter = ZERO_INIT,l_coulmns_counter = ZERO_INIT,l_counter=ZERO_INIT,column_logic=ZERO_INIT;
    if((keypad == NULL)|| (value== NULL)){
        ret = E_NOT_OK;
    }
    else 
    {
        for(l_rows_counter =ZERO_INIT;l_rows_counter<ECU_KEYPAD_ROW;l_rows_counter++){
             for(l_counter =ZERO_INIT;l_counter<ECU_KEYPAD_ROW;l_counter++){
                 ret = gpio_pin_write_logic(&(keypad->keypad_row_pins[l_counter]),GPIO_LOW);
            }
             ret = gpio_pin_write_logic(&(keypad->keypad_row_pins[l_rows_counter]),GPIO_HIGH);
            for(l_coulmns_counter =ZERO_INIT;l_coulmns_counter<ECU_KEYPAD_ROW;l_coulmns_counter++){
                ret = gpio_pin_read_logic(&(keypad->keypad_coulmn_pins[l_coulmns_counter]),&column_logic);
                if(column_logic == GPIO_HIGH){
                    *value = btn_values[l_rows_counter][l_coulmns_counter];
                }
            }
        }
    }
    return ret;
    
    
}