/*
 * Dio.h
 *
 * Created: 15/09/2021 14:24:29
 *  Author: ashraf
 */ 



#ifndef DIO_H_
#define DIO_H_

void Dio_vSetPinDir(unsigned char port,unsigned char pin ,unsigned char direction);

void DIO_vWrite_pin(unsigned char port,unsigned char pin,unsigned char value);

void DIO_vToggle_pin(unsigned char port,unsigned char pin);

unsigned char DIO_u8Read_pin(unsigned char port,unsigned char pin);

void DIO_set_port_direction(unsigned char portname,unsigned char direction);

void DIO_write_port(unsigned char portname,unsigned char value);

unsigned char DIO_u8Read_port(unsigned char portname);

void vToggle_port(unsigned char portname);
void DIO_vEnable_Internal_PULLUP(unsigned char port,unsigned char pin,unsigned char Enable_Disable);


void write_low_nibble(unsigned char portname,unsigned char value);
void write_high_nibble(unsigned char portname,unsigned char value);


#endif /* DIO_H_ */