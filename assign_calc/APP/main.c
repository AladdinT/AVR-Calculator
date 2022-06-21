/*
 * main.c
 *
 *  Created on: Sep 6, 2021
 *      Author: ahmad
 */
#define F_CPU 8000000UL
#include "../HAL/LCD/LCD_interface.h"
#include "../HAL/KEYPAD/KEYPAD_interface.h"
#include <util/delay.h>

s32 string_to_int (u8 str[] , u8 index){
	s32 num = 0;
	//cast it into an integer
	for(int j = 0 ;j < index-1 ; j++){

		num = (str[j] - '0') + (num*10) ;//0b0000 0001
	}

	return num;
}
int main (void){
	KEYPAD_Init();
	LCD_Init();
	u8 key = 0;
	u8 keymap[17] = {
		0,
		'7','8','9','/',
		'4','5','6','*',
		'1','2','3','-',
		'C','0','=','+'
	};
	u8 key_input[16]={0};
	u8 i = 0;
	s32 fst_operand = 0;
	s32 sec_operand = 0;
	f32 ans = 0;
	u8 operator = 0;
	u8 clr_flag = 0;
	u32 decimals = 0;
	while(1){

		//Save input as an array of char
		key = keymap[KEYPAD_LastPressedKey()];

		if(key != 0 ){
			LCD_SendChar(key);
			key_input[i] = key ;
			i++;
			if(clr_flag == 1)
			{
				LCD_SendCommand(1);
				clr_flag = 0;
				i=0;
			}
		}
		//Translate the array to nums for 1st int
		if(key == '=' )
		{
			sec_operand = string_to_int(key_input, i);
			if(operator == '+'){
				ans = fst_operand + sec_operand;
			}else if(operator == '-'){
				ans = fst_operand - sec_operand;
			}else if(operator == '*'){
				ans = fst_operand * sec_operand;
			}else if(operator == '/'){
				ans = (float) ((float) fst_operand / (float) sec_operand);
				int intans = (int) ans;
				float fans = ans*100;
				decimals = (int)fans - intans*100;
			}
			SetCursorPos(1,0);
			LCD_PrintNum(ans);
			if(operator == '/'){
				LCD_SendChar('.');
				LCD_PrintNum(decimals);
			}
			clr_flag = 1;

		}else if( !(key >= '0' && key <='9') && key != 0){

			if(key == 'C')
				clr_flag = 1;

			operator = key;
			fst_operand = string_to_int(key_input,i);

			i=0;
		}



	}


}
