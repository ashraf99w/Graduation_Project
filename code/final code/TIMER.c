/*
 * TIMER.c
 *
 * Created: 30/09/2021 13:00:27
 *  Author: ashraf
 */ 

#include <avr/interrupt.h>
#include "Macros.h"
void Timer0_CTC_init_interrupt(void)
{
	Set_bit(TCCR0,WGM01);// CTC MODE
	//PRESCALAR 1024
	Set_bit(TCCR0,CS00);
    Set_bit(TCCR0,CS02);	
	//TO MAKE 10ms
	OCR0=80;
	sei();
	Set_bit(TIMSK,OCIE0);
}

void Timer0_wave_nonPWM(void)
{
	/* set OC0 as output pin */
	Set_bit(DDRB,3);
	/* select CTC mode*/
	Set_bit(TCCR0,WGM01);
	/* load a value in OCR0 */
	OCR0=64;
	/* select timer clock */
	Set_bit(TCCR0,CS00);
	Set_bit(TCCR0,CS02);
	/* toggle OC0 on compare match*/
	Set_bit(TCCR0,COM00);
}
void Timer0_wave_PWM( int x)
{
		/* set OC0 as output pin */
		Set_bit(DDRB,3);
		/* select FAST PWM mode*/
		Set_bit(TCCR0,WGM01);
		Set_bit(TCCR0,WGM00);
		/* load a value in OCR0 */
		OCR0= 255*x/100;
		/* select timer clock */
		Set_bit(TCCR0,CS00);
		Set_bit(TCCR0,CS01);
	    //select non-inverting mode clear on compare match and set on bottom
		Set_bit(TCCR0,COM01);
		Clear_bit(TCCR0,COM00);
}

void Timer2_wave_PWM( signed char x)
{
	/* set OC2 as output pin */
	Set_bit(DDRD,7);
	/* select FAST PWM mode*/
	Set_bit(TCCR2,WGM20);
	Set_bit(TCCR2,WGM21);
	
	/* select timer clock */
	Set_bit(TCCR2,CS20);
	
	/* load a value in OCR2 */
	OCR2= 255*x/100;;
	
	
	
	//CLEAR OC2 0n compare match and SET OC2 at Bottom
	Set_bit(TCCR2,COM21);
	Clear_bit(TCCR2,COM20);
}

void Timer0_NORMAL_MODE_init(unsigned char interrupt_enable)
{
	//PRESCALLING F_CPU/256
	Set_bit(TCCR0,CS02);
	Clear_bit(TCCR0,CS01);
	Clear_bit(TCCR0,CS00);
	
	if(interrupt_enable==1)
	{
		sei();
		Set_bit(TIMSK,TOIE0);
	}

	
}
void Timer2_NORMAL_MODE_init(unsigned char interrupt_enable)
{
	//PRESCALLING F_CPU/256
	Clear_bit(TCCR2,CS20);
	Set_bit(TCCR2,CS22);
	Set_bit(TCCR2,CS21);
	if(interrupt_enable==1)
	{
		sei();
		Set_bit(TIMSK,TOIE2);
	}
}

void Timer1_IC_MODE_init(unsigned char interrupt_enable)

{
	//rising edge /no prescaller
	
	Set_bit(TCCR1B,6);
	Set_bit(TCCR1B,CS10);
	if(interrupt_enable==1)
	{
			sei();
			Set_bit(TIMSK,TICIE1);
	}

	
	
}



void Timer1_FastPWM_OC1A_SERVO_DC(float base_SERVO,float sub_SERVO,float SPEED_VALUE)
{
	//set OC1A as output pin
	Set_bit(DDRD,5);
	
	//set OC1B as output pin
	Set_bit(DDRD,4);
	
	//select Fast PWM , TOP =Icr1
	Set_bit(TCCR1A,WGM11);
	Set_bit(TCCR1B,WGM12);
	Set_bit(TCCR1B,WGM13);
	
	ICR1=19999;//PW REPEATED EACH 20 ms
	OCR1A=base_SERVO*1000 + sub_SERVO*(5.55556);//5.555556 micro seconds needed for one degree
	
	OCR1B=(SPEED_VALUE/100)*19999;
    //no prescaling
    Set_bit(TCCR1B,CS10);
	//select non-inverting mode clear on compare match and set on bottom
	Set_bit(TCCR1A,COM1A1);
	Set_bit(TCCR1A,COM1B1);
}

void Timer1_FastPWM_OC1B(float sub_SERVO)
{
	//set OC1B as output pin
	Set_bit(DDRD,4);

	//select Fast PWM ,TOP =OCR1A
	Set_bit(TCCR1A,WGM10);
	Set_bit(TCCR1A,WGM11);
	Set_bit(TCCR1B,WGM12);
	Set_bit(TCCR1B,WGM13);
	
	OCR1A=19999;//PW REPEATED EACH 20 ms
    OCR1B= 1500 + sub_SERVO*(5.55556);//5.555556 micro seconds needed for one degree
	
    //no prescaling
	Set_bit(TCCR1B,CS10);
    //select non-inverting mode clear on compare match and set on bottom
    Set_bit(TCCR1A,COM1B1);
	 	 
}