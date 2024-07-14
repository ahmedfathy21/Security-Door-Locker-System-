/* 
 * File:   ECU_layer_init.c
 * Author: En.Ahmed
 *
 * Created on April 17, 2024, 12:35 AM
 */
#include"ECU_layer_init.h"
chr_lcd_4bit_t  lcd = {
  .lcd_rs.port = PORTC_INDEX,
  .lcd_rs.pin  = PIN0 ,
  .lcd_rs.direction = GPIO_DIRECTION_OUTPUT,
  .lcd_rs.logic = GPIO_LOW,
  .lcd_en.port = PORTC_INDEX,
  .lcd_en.pin  = PIN1 ,
  .lcd_en.direction = GPIO_DIRECTION_OUTPUT,
  .lcd_en.logic = GPIO_LOW,
  .lcd_data[0].port = PORTC_INDEX,
  .lcd_data[0].pin = PIN2,
  .lcd_data[0].direction = GPIO_DIRECTION_OUTPUT,
  .lcd_data[0].logic = GPIO_LOW,
  .lcd_data[1].port = PORTC_INDEX,
  .lcd_data[1].pin = PIN3,
  .lcd_data[1].direction = GPIO_DIRECTION_OUTPUT,
  .lcd_data[1].logic = GPIO_LOW,
  .lcd_data[2].port = PORTC_INDEX,
  .lcd_data[2].pin = PIN4,
  .lcd_data[2].direction = GPIO_DIRECTION_OUTPUT,
  .lcd_data[2].logic = GPIO_LOW,
  .lcd_data[3].port = PORTC_INDEX,
  .lcd_data[3].pin = PIN5,
  .lcd_data[3].direction = GPIO_DIRECTION_OUTPUT,
  .lcd_data[3].logic = GPIO_LOW,
};
keypad_t keypad ={
  .keypad_row_pins[0].port=PORTD_INDEX,
  .keypad_row_pins[0].pin=PIN0,
  .keypad_row_pins[0].direction=GPIO_DIRECTION_OUTPUT,
  .keypad_row_pins[0].logic=GPIO_LOW,
  .keypad_row_pins[1].port=PORTD_INDEX,
  .keypad_row_pins[1].pin=PIN1,
  .keypad_row_pins[1].direction=GPIO_DIRECTION_OUTPUT,
  .keypad_row_pins[1].logic=GPIO_LOW,
  .keypad_row_pins[2].port=PORTD_INDEX,
  .keypad_row_pins[2].pin=PIN2,
  .keypad_row_pins[2].direction=GPIO_DIRECTION_OUTPUT,
  .keypad_row_pins[2].logic=GPIO_LOW,
  .keypad_row_pins[3].port=PORTD_INDEX,
  .keypad_row_pins[3].pin=PIN3,
  .keypad_row_pins[3].direction=GPIO_DIRECTION_OUTPUT,
  .keypad_row_pins[3].logic=GPIO_LOW,  
  
  .keypad_coulmn_pins[0].port=PORTD_INDEX,
  .keypad_coulmn_pins[0].pin=PIN4,
  .keypad_coulmn_pins[0].direction=GPIO_DIRECTION_INPUT,
  .keypad_coulmn_pins[0].logic=GPIO_LOW,
  .keypad_coulmn_pins[1].port=PORTD_INDEX,
  .keypad_coulmn_pins[1].pin=PIN5,
  .keypad_coulmn_pins[1].direction=GPIO_DIRECTION_INPUT,
  .keypad_coulmn_pins[1].logic=GPIO_LOW,
  .keypad_coulmn_pins[2].port=PORTD_INDEX,
  .keypad_coulmn_pins[2].pin=PIN6,
  .keypad_coulmn_pins[2].direction=GPIO_DIRECTION_INPUT,
  .keypad_coulmn_pins[2].logic=GPIO_LOW,
  .keypad_coulmn_pins[3].port=PORTD_INDEX,
  .keypad_coulmn_pins[3].pin=PIN7,
  .keypad_coulmn_pins[3].direction=GPIO_DIRECTION_INPUT,
  .keypad_coulmn_pins[3].logic=GPIO_LOW,
};
led_t Led_Locked = {.port_name = PORTE_INDEX , .pin = PIN0, .led_status = LED_OFF};
led_t Led_UnLocked = {.port_name = PORTE_INDEX , .pin = PIN1, .led_status = LED_OFF};

 dc_motor_t Motor = {.dc_motor_pin[0].port = PORTB_INDEX , .dc_motor_pin[0].pin = PIN0 ,
                      .dc_motor_pin[0].direction = GPIO_DIRECTION_OUTPUT ,.dc_motor_pin[0].logic = GPIO_LOW,
                      .dc_motor_pin[1].port = PORTB_INDEX , .dc_motor_pin[1].pin = PIN1 ,
                      .dc_motor_pin[1].direction = GPIO_DIRECTION_OUTPUT ,.dc_motor_pin[1].logic = GPIO_LOW,};

void ecu_layer_initialize(void){ 
    std_ReturnType ret = E_NOT_OK;
    ret = keypad_initialize(&keypad);
    ret = lcd_4bit_initialize(&lcd);
    ret = led_initialize(&Led_UnLocked);
    ret = led_initialize(&Led_Locked);
    ret = dc_motor_initialize(&Motor);
    
}