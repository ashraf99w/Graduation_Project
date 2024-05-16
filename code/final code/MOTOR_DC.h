/*
 * MOTOR_DC.h
 *
 * Created: 03/10/2021 16:08:39
 *  Author: ashraf
 */ 


#ifndef MOTOR_DC_H_
#define MOTOR_DC_H_

void DC_MOTOR(unsigned char direction ,unsigned char portname,unsigned char speed);
void DC_MOTOR_SERVO(unsigned char direction ,unsigned char portname,float speed_dc,float sub_SERVO);



#endif /* MOTOR_DC_H_ */