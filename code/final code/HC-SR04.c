/*
 * HC_SR04.c
 *
 * Created: 02/10/2021 00:16:41
 *  Author: ashraf
 */ 
#include <avr/interrupt.h>
#include "TIMER.h"
#include "Dio.h"
#define  F_CPU 1000000UL
#include <util/delay.h>
extern volatile unsigned short a;
extern volatile unsigned short b;
extern volatile unsigned char  c;
extern volatile unsigned char  OVERFLOW0;
extern volatile unsigned char  OVERFLOW2;
extern volatile unsigned char  d;
#include "Macros.h"

 unsigned short  HC_SRNSOR_INIT_timer0(unsigned char portname,unsigned char pin)
{
	    unsigned short distance=0;
        Dio_vSetPinDir(portname,pin,1);
		DIO_vWrite_pin(portname,pin,1);
		_delay_us(50);
        DIO_vWrite_pin(portname,pin,0);  
		 sei();
		 Set_bit(GICR,INT0);
		 Set_bit(MCUCR,ISC00);
		 Set_bit(MCUCR,ISC01);
		 Set_bit(TIMSK,TOIE0);
		 while(c==0);

		 distance= (OVERFLOW0*256 + c)*34600/(F_CPU * 2);
		 c=0;
		 OVERFLOW0=0;
   	return distance;
}
 unsigned short  HC_SRNSOR_INIT_timer2(unsigned char portname,unsigned char pin)
 { unsigned short distance=0;
	 Dio_vSetPinDir(portname,pin,1);
	 DIO_vWrite_pin(portname,pin,1);
	 _delay_us(50);
	 DIO_vWrite_pin(portname,pin,0);
	    sei();
	    Set_bit(GICR,INT2);
		Set_bit(MCUCSR,ISC2);
	 	 Set_bit(TIMSK,TOIE2);
	 	 
	 while(d==0);
	 distance= (OVERFLOW2*256 + d)*34600/(F_CPU * 2);
	 d=0;
	 OVERFLOW2=0;
	 return distance;
	 
	
	 
 }


	
	unsigned short  HC_SR04_INIT_timer1(unsigned char portname,unsigned char pin)
	{  
	    unsigned short high,a,b;
		unsigned short distance=0;
		
		TCCR1A = 0;
		TIFR |= (1<<ICF1);  	/* Clear ICF (Input Capture flag)  */
		
		Dio_vSetPinDir(portname,pin,1);
		DIO_vWrite_pin(portname,pin,1);
		_delay_us(20);
		DIO_vWrite_pin(portname,pin,0);
		TCCR1B = 0xc1;  	/* Rising edge, no prescaler , noise canceler*/
		while ((TIFR&(1<<ICF1)) == 0);
		a = ICR1;  		/* Take value of capture register */
		TIFR |= (1<<ICF1);  	/* Clear ICF flag */
		TCCR1B = 0x81;  	/* Falling edge, no prescaler ,noise canceler*/
		while ((TIFR&(1<<ICF1)) == 0);
		b = ICR1;  		/* Take value of capture register */
		TIFR |= (1<<ICF1);  	/* Clear ICF flag */
		TCNT1=0;
		TCCR1B = 0;  		/* Stop the timer */
		high=b-a;
		distance=((high*34600)/(F_CPU*2));
		a=b=high=0;
		return distance;
		
	}
	
		
		unsigned short  HC_SR04_INIT_timer1_new(unsigned char portname,unsigned char pin)
		{
			unsigned short high,a,b;
			unsigned short distance;
			TIFR |= (1<<ICF1);  	/* Clear ICF (Input Capture flag)  */
			
			/* Rising edge, noise canceler*/
			Set_bit(TCCR1B,ICNC1);
			Set_bit(TCCR1B,6);
			
			Dio_vSetPinDir(portname,pin,1);
			DIO_vWrite_pin(portname,pin,1);
			_delay_us(15);
			DIO_vWrite_pin(portname,pin,0);
			
			
			
			while ((TIFR&(1<<ICF1)) == 0);
			
			a = ICR1;  		/* Take value of capture register */
			TIFR |= (1<<ICF1);  	/* Clear ICF flag */
			
			Clear_bit(TCCR1B,6); /* Falling edge*/
			
			while ((TIFR&(1<<ICF1)) == 0);
			b = ICR1;  		/* Take value of capture register */
			TIFR = (1<<ICF1);  	/* Clear ICF flag */
			if ( b > a)
			{
				high=b-a;
				distance=((high*34600)/(F_CPU*2));
				a=b=high=0;
			}
			
			else
			{
				high = (19999-a) + b;
				distance=((high*34600)/(F_CPU*2));
				a=b=high=0;	
			}
			
			return distance;
			
		}