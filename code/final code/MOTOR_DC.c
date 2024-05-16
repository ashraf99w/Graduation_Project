/*
 * MOTOR_DC.c
 *
 * Created: 03/10/2021 16:08:26
 *  Author: ashraf
 */ 

#include "Dio.h"
#include "TIMER.h"
void DC_MOTOR(unsigned char direction ,unsigned char portname,unsigned char speed)
{
	// Set First Four Fins As Output Pins
	DIO_set_port_direction(portname,0x0f);
	switch (direction)
	{
		//Case Forward Direction
		case 'f':
		case 'F':
		DIO_write_port(portname,0x05);
		
		break;
		//Case Backward Direction
		case 'b':
		case 'B':
		DIO_write_port(portname,0x0A);
		
		break;
		
		
	}
	//Choose The Speed of the DC motors
	Timer0_wave_PWM(speed);
}

void DC_MOTOR_SERVO(unsigned char direction ,unsigned char portname,float speed_dc,float sub_SERVO)
{
	// Set First Four Fins As Output Pins
	DIO_set_port_direction(portname,0x0f);
	switch (direction)
	{
		//Case Forward Direction
		case 'f':
		case 'F':
		DIO_write_port(portname,0x05);
		
		break;
		//Case Backward Direction
		case 'b':
		case 'B':
		DIO_write_port(portname,0x0A);
		
		break;
		
		
	}
	//Choose The Speed of the DC motors
	Timer1_FastPWM_OC1A_SERVO_DC(1.5,sub_SERVO,speed_dc);
}




