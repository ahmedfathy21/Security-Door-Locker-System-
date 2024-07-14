/* 
 * File:   Application.c
 * Author: En.Ahmed
 *
 * Created on March 4, 2024, 6:40 PM
 */


#include"application.h"

std_ReturnType ret = E_OK;  
uint8 Keypad_Value = 0;
uint32 entered_password = 0;
uint32 Password = 123456;
uint8 lcd_output_data_col = 20;
uint8 number_of_clicks = 0;
uint8 Incorrect_Pass = 0;
uint8 Try_Number = '2';
int main()
{
    application_initialize();
    ret = lcd_4bit_send_string(&lcd , "Hello Ahmed !!");
    __delay_ms(1000);
    Clear_Lcd();
    ret = lcd_4bit_send_string(&lcd , "Enter Password : ");
    
    while(1)
    {
        /* Read Keypad value */
       Keypad_Value = keypad_read_value();
       if(number_of_clicks == 6 ){
           /* Reset Variables*/
           number_of_clicks = 0;
           lcd_output_data_col = 20;
           /* if the pass is valid >>> turn on the Gree led and move the Motor Right  */
           if( Password == entered_password ){
               Unlocked_Led_On();
               Motor_Right();
               Clear_Lcd();
               ret = lcd_4bit_send_string_pos(&lcd ,1,4, "DOOR UNLOCKED!");
                ret = lcd_4bit_send_string_pos(&lcd ,2,4, "Welcome Ahmed! ");
                Incorrect_Pass = 0;
                __delay_ms(ACTIVE_TIME);
                 Unlocked_Led_Off();
                 Clear_Lcd();
                 Motor_Stop();
                 Clear_Lcd();
              ret = lcd_4bit_send_string(&lcd , "Enter Password : ");
              
                 
           }
           else
              
           {
                /*Password not valid >>> Turn On Led Red and move Motor Left */
              
                 locked_Led_On();
                 Clear_Lcd();
                 ret = lcd_4bit_send_string_pos(&lcd ,1,2, "Incorrect Password");
                 ret = lcd_4bit_send_string_pos(&lcd ,2,1, "remain   times");
                 ret = lcd_4bit_send_char_data_pos(&lcd,2,8,Try_Number);
                 Try_Number--;
                 Motor_Left();
                 Incorrect_Pass++;
                 __delay_ms(DIS_ACTIVE_TIME);
                 locked_Led_Off();
                  Clear_Lcd();
                 Motor_Stop();
                 ret = lcd_4bit_send_string(&lcd , "Enter Password : ");
           }
           if(Incorrect_Pass == 3)
           {
               /* if the user enter wrong pass 3 times >> wait 60 second before try again */
                Clear_Lcd();
                ret = lcd_4bit_send_string_pos(&lcd ,1,1, "Try again in     Sec");
                 uint8 _char = 0;
                for(uint8 counter = 60 ; counter > 0 ; counter--){
                    _char = '0' + (counter % 10);
                    ret = lcd_4bit_send_char_data_pos(&lcd, 1, 16, _char);
                    _char = '0' + ((counter/10) % 10);
                    ret = lcd_4bit_send_char_data_pos(&lcd, 1, 15, _char);
                    locked_Led_On();
                    __delay_ms(500);
                    locked_Led_Off();
                    __delay_ms(500);
                     
                }
                 Incorrect_Pass = 0;
                 Clear_Lcd();
                 ret = lcd_4bit_send_string(&lcd , "Enter Password : ");
                 Try_Number = 2;
                 
           }
           
            entered_password = 0;
       }
        /* Taking password from the user */
        if('0' <= Keypad_Value && Keypad_Value <= '9')
        {
            number_of_clicks++;
            /* storing entered password */
           entered_password = (entered_password * 10) + (Keypad_Value - '0');
           ret = lcd_4bit_send_char_data_pos(&lcd, 2, ++lcd_output_data_col, Keypad_Value);
           __delay_ms(100);
           ret = lcd_4bit_send_char_data_pos(&lcd, 2, lcd_output_data_col, '*');
           
        }
        else{ /* Nothing */ }
      
       
        
    }
    
     return (EXIT_SUCCESS);
}
void application_initialize(void){       
ecu_layer_initialize();
}
uint8 keypad_read_value()
{
    uint8 keypad_pressed_value = 0;
    do {
        __delay_ms(20);
        ret = keypad_get_value(&keypad, &keypad_pressed_value);
    } while(0 == keypad_pressed_value);
    __delay_ms(DEBOUNE_TIME);
    return keypad_pressed_value;  
}


void Clear_Lcd(){
    lcd_4bit_send_command(&lcd , _LCD_CLEAR);
    
}

void Unlocked_Led_On(){
ret = led_turn_on(&Led_UnLocked);

}

void locked_Led_On(){
ret = led_turn_on(&Led_Locked);

}

void Unlocked_Led_Off(){
ret = led_turn_off(&Led_UnLocked);

}
void locked_Led_Off(){
ret = led_turn_off(&Led_Locked);

}
void Motor_Right(){  
    ret = dc_motor_move_right(&Motor);
}
void Motor_Left(){  
    ret = dc_motor_move_left(&Motor);
}
void Motor_Stop(){
    
    ret = dc_motor_stop(&Motor);
}