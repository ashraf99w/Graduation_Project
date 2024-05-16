/*
 * LED.c
 *
 * Created: 16/09/2021 16:07:03
 *  Author: ashraf
 */ 
#include "Dio.h"
void LED_vInit(unsigned char portname,unsigned char pinnumber)
{
	Dio_vSetPinDir(portname,pinnumber,1);
}




void LED_vTurnOn(unsigned char portname,unsigned char pinnumber)
{
	DIO_vWrite_pin(portname,pinnumber,1);
}




void LED_vTurnOff(unsigned char portname,unsigned char pinnumber)
{
	DIO_vWrite_pin(portname,pinnumber,0);
}




void LED_vToggle(unsigned char portname,unsigned char pinnumber)
{
	DIO_vToggle_pin(portname,pinnumber);
}




unsigned char  LED_u8Status(unsigned char portname,unsigned char pinnumber)
{
	return DIO_u8Read_pin(portname,pinnumber);
}
void LED8_vInitialize(unsigned char portname,unsigned char direction)
{
	DIO_set_port_direction(portname,direction);
}