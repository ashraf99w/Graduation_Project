/*
 * LED.h
 *
 * Created: 16/09/2021 16:06:51
 *  Author: ashraf
 */ 


#ifndef LED_H_
#define LED_H_

void LED_vInit(unsigned char portname,unsigned char pinnumber);
void LED_vTurnOn(unsigned char portname,unsigned char pinnumber);
void LED_vTurnOff(unsigned char portname,unsigned char pinnumber);
void LED_vToggle(unsigned char portname,unsigned char pinnumber);
unsigned char  LED_u8Status(unsigned char portname,unsigned char pinnumber);
void LED8_vInitialize(unsigned char portname,unsigned char direction);


#endif /* LED_H_ */