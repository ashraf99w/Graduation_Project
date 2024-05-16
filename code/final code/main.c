/*
 * new.c
 *
 * Created: 16/04/2022 05:14:49 م
 * Author : ashraf
 */ 

#include <avr/io.h>
#define F_CPU 1000000UL
#include <avr/interrupt.h>
#include <util/delay.h>
#include "Macros.h"
#include "Dio.h"
#include "HC-SR04.h"
#include "TIMER.h"
#include "LED.h"
#include "MOTOR_DC.h"

volatile unsigned short a=0;
volatile unsigned short b=0;
volatile unsigned char  c=0;
volatile unsigned char  OVERFLOW0=0;
volatile unsigned char  OVERFLOW2=0;
volatile unsigned char  d=0;
volatile unsigned char  COUNTER0=0,COUNTER2=0;
volatile unsigned char  counter=0;

int main(void)
{
	 _delay_ms(3000);
   //space_car  is the distance between us and the stationary cars
    unsigned short space_car,BACK_LEFT,BACK_RIGHT; 
	  
	Dio_vSetPinDir('D',2,0);
    LED_vInit('B',0);//INDICATION OF GOOD SPACE TO PARK
	LED_vInit('c',5);//INDICATION OF TAKING PARKING ACTION
	LED_vInit('B',1);//INDICATION OF SMALL PLACE
	LED_vInit('B',2);//FOR BAZZER
    // to choose the channel of multiplexer
    LED_vInit('c',3);
    LED_vInit('c',4);
	// to choose the first channel
	LED_vTurnOff('C',3);
	LED_vTurnOff('C',4);
	 
	 //enable interrupt 0
	 Set_bit(GICR,INT0);
	 //choose rising edge
	 Set_bit(MCUCR,ISC00);
	 Set_bit(MCUCR,ISC01);
	 
	
	Timer1_FastPWM_OC1B(-2);
	
	_delay_ms(600);
	while(1)
	{  
		     DC_MOTOR('F','A',25);
		     space_car=HC_SR04_INIT_timer1_new('C',0);
			 _delay_ms(10);
			 while(space_car <= 15)
			 {
				space_car=HC_SR04_INIT_timer1_new('C',0);// uses timer 1	
				  _delay_ms(10);	 	 
			 }
			 
	         sei();
			 while(space_car > 15)
			 {
				 space_car=HC_SR04_INIT_timer1_new('C',0);// uses timer 1
				 _delay_ms(10);	 
				 if (counter >= 60)
				 break;
				
			 }
			 DC_MOTOR('F','A',0);
	         cli();
			
				
			if ( counter >= 60)
			{
				counter=0;
				//indication of a good space to bark
				LED_vTurnOn('B',0);
				_delay_ms(1000);
				LED_vTurnOff('B',0);
				
				
				//TO CHOOSE CHANNEL 1
				LED_vTurnOn('C',4);
				_delay_ms(1000);
			
	            Timer1_FastPWM_OC1B(60);		
				_delay_ms(700);
				DC_MOTOR('B','A',30);
				BACK_RIGHT= HC_SR04_INIT_timer1_new('C',1);
				_delay_ms(10);
				
				// executed
				
				while(BACK_RIGHT >= 20)
				{
					BACK_RIGHT= HC_SR04_INIT_timer1_new('C',1);
					_delay_ms(10);	
				}

				
                
		        DC_MOTOR('B','A',0);
				_delay_ms(1000);
				
				Timer1_FastPWM_OC1B(-60);
				_delay_ms(1000);
				
				//HERE YOU SHOULD CHOOSE CHANNEL 3
				LED_vTurnOff('C',4);
				LED_vTurnOn('C',3);
			
				BACK_LEFT=HC_SR04_INIT_timer1_new('C',2);
				_delay_ms(10);
		        
				while(BACK_LEFT >= 11)
				{
					DC_MOTOR('B','A',30);
					LED_vTurnOn('C',5);
					_delay_ms(10);
					BACK_LEFT=HC_SR04_INIT_timer1_new('C',2);
					
				}
				DC_MOTOR('B','A',0);
				
				_delay_ms(1000);
				Timer1_FastPWM_OC1B(-2);
				_delay_ms(1000); 
				
				//buzzer on/off
				LED_vTurnOn('B',2);
				_delay_ms(500);
				LED_vTurnOff('B',2);
				_delay_ms(500);
		 
				LED_vTurnOn('B',2);
				_delay_ms(500);
				LED_vTurnOff('B',2);
				_delay_ms(500);
		  
				LED_vTurnOn('B',2);
				_delay_ms(500);
				LED_vTurnOff('B',2);
				_delay_ms(500);
				break;
			 
		  
			}
		else
		{
			counter=0;
			LED_vTurnOn('B',1);
			_delay_ms(2000);
			LED_vTurnOff('B',1);
			
		}
	 
	 
	 
	}
				   
}


ISR(INT0_vect)
{
	counter++;
}
