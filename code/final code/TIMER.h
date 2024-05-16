/*
 * TIMER.h
 *
 * Created: 30/09/2021 13:00:50
 *  Author: ashraf
 */ 


#ifndef TIMER_H_
#define TIMER_H_


void Timer0_CTC_init_interrupt(void);
void Timer0_wave_nonPWM(void);
void Timer0_wave_PWM( int x);
void Timer0_NORMAL_MODE_init(unsigned char interrupt_enable);
void Timer2_NORMAL_MODE_init(unsigned char interrupt_enable);
void Timer1_IC_MODE_init(unsigned char interrupt_enable);
void Timer1_FastPWM_OC1A_SERVO_DC(float base_SERVO,float sub_SERVO,float SPEED_VALUE);
void Timer2_wave_PWM( signed char x);
void Timer1_FastPWM_OC1B(float sub_SERVO);

#endif /* TIMER_H_ */