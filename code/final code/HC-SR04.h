/*
 * HC_SR04.h
 *
 * Created: 02/10/2021 00:16:19
 *  Author: ashraf
 */ 


#ifndef  HCSR04_H_
#define  HCSR04_H_


 double  HC_SRNSOR_INIT_timer0(unsigned char portname,unsigned char pin);
 double  HC_SRNSOR_INIT_timer2(unsigned char portname,unsigned char pin);
unsigned short  HC_SR04_INIT_timer1(unsigned char portname,unsigned char pin);
unsigned short  HC_SR04_INIT_timer1_new(unsigned char portname,unsigned char pin);


#endif /* HC-SR04_H_ */