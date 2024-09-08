/*
 * the safe.c
 *
 * Created: 9/8/2024 7:13:16 PM
 * Author : Al-Arab
 */ 

#include <avr/io.h>
#include "LCD.h"
#include "keypad_driver.h"
#include "EEPROM_driver.h"
#define F_CPU 8000000UL
#include <util/delay.h>

#define  location_adderss  0x30
#define  password_number1 0x31
#define  password_number2 0x32
#define  password_number3 0x33
#define  password_number4 0x34
#define MAX_TRIES 3

char number1,number2,number3,number4;
int main()
{
	char tries=MAX_TRIES;
	LCD_vInit();
	keypad_vInit();
	char x;
	//char number1,number2,number3,number4;
	
	if(EEPROM_read(location_adderss)==0xff)
	{
		//char value;
		LCD_movecursor(1,4);
		LCD_vSend_string("Hello Reem");
		_delay_ms(800);
		LCD_clearscreen();
		LCD_movecursor(1,1);
		LCD_vSend_string("Password=");
		for(char i=0;i<=3;i++)
		{
			do
			{
				x= keypad_u8check_press();
			}while(x==0xff);
			LCD_vSend_char(x);
			_delay_ms(500);
			LCD_movecursor(1,10+i);
			LCD_vSend_char('*');
			_delay_ms(500);
			EEPROM_write(password_number1+i,x);
		}
		EEPROM_write(location_adderss,0x00);
	}
	
	while(1)
	{
		number1=number2=number3=number4=0xff;
		LCD_clearscreen();
		LCD_vSend_string("check pass:");
		do
		{
			number1= keypad_u8check_press();
		} while (number1==0xff);
		LCD_vSend_char(number1);
		_delay_ms(500);
		LCD_movecursor(1,12);
		LCD_vSend_char('*');
		_delay_ms(500);
		
		do
		{
			number2= keypad_u8check_press();
		} while (number2==0xff);
		LCD_vSend_char(number2);
		_delay_ms(500);
		LCD_movecursor(1,13);
		LCD_vSend_char('*');
		_delay_ms(500);
		
		do
		{
			number3= keypad_u8check_press();
		} while (number3==0xff);
		LCD_vSend_char(number3);
		_delay_ms(500);
		LCD_movecursor(1,14);
		LCD_vSend_char('*');
		_delay_ms(500);
		do
		{
			number4= keypad_u8check_press();
		} while (number4==0xff);
		LCD_vSend_char(number4);
		_delay_ms(500);
		LCD_movecursor(1,15);
		LCD_vSend_char('*');
		_delay_ms(500);
		if(EEPROM_read(password_number1)==number1&&
		EEPROM_read(password_number2)==number2&&
		EEPROM_read(password_number3)==number3&&
		EEPROM_read(password_number4)==number4)
		{
			LCD_clearscreen();
			LCD_vSend_string("Right Password");
			LCD_movecursor(2,1);
			LCD_vSend_string("lock opened");
			break;
		}
		else
		{
			
			tries=tries-1;
			if (tries>0)
			{
				LCD_clearscreen();
				LCD_vSend_string("wrong password");
				_delay_ms(1000);
				LCD_clearscreen();
				LCD_vSend_string("tries left:");
				LCD_vSend_char(tries+'0');
				_delay_ms(1000);
				
			}
			
			else
			{
				LCD_clearscreen();
				LCD_vSend_string("wrong password");
				LCD_movecursor(2,1);
				LCD_vSend_string("lock closed");
				break;
			}
		}
	}
}



