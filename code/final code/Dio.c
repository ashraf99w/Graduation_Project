/*
 * Dio.c
 *
 * Created: 15/09/2021 14:25:49
 *  Author: ashraf
 */ 
#include <avr/io.h>
#include "Macros.h"

void Dio_vSetPinDir(unsigned char port,unsigned char pin ,unsigned char direction)
{
	switch(port)
	{
		// FOR PORT A
		case 'A':
		case 'a':
			if(direction==1)
			{Set_bit(DDRA,pin);}
			
			else
			{Clear_bit(DDRA,pin);}
			
           break;
			
			// FOR PORT B
			case 'b':
			case 'B':
				if(direction==1)
				{Set_bit(DDRB,pin);}

				else
				{Clear_bit(DDRB,pin);}
				break;
			
			
			
			
			// FOR PORT C
			case 'C':
			case 'c':
				if(direction==1)
				{Set_bit(DDRC,pin);}
				else
				{Clear_bit(DDRC,pin);}
				break;
			

            // FOR PORT D
            case 'D':
            case 'd':
            if(direction==1)
            {Set_bit(DDRD,pin);}
            else
            {Clear_bit(DDRD,pin);}
            break;
			

			
			
			
	}
}

void DIO_vWrite_pin(unsigned char port,unsigned char pin,unsigned char value)
{
	switch(port)
	{
		// FOR PORT A
		case 'A':
		case 'a':
		if(value==1)
		{Set_bit(PORTA,pin);}
		
		else
		{Clear_bit(PORTA,pin);}
		
		break;
		
		// FOR PORT B
		case 'b':
		case 'B':
		if(value==1)
		{Set_bit(PORTB,pin);}

		else
		{Clear_bit(PORTB,pin);}
		break;
		
		
		
		
		// FOR PORT C
		case 'C':
		case 'c':
		if(value==1)
		{Set_bit(PORTC,pin);}
		else
		{Clear_bit(PORTC,pin);}
		break;
		

		// FOR PORT D
		case 'D':
		case 'd':
		if(value==1)
		{Set_bit(PORTD,pin);}
		else
		{Clear_bit(PORTD,pin);}
		break;				
	}
}


void DIO_vToggle_pin(unsigned char port,unsigned char pin)
{
	switch(port)
	{
		case 'A':
		case 'a':
		Toggle_bit(PORTA,pin);
		break;
		
		
		case 'b':
		case 'B':
		Toggle_bit(PORTB,pin);
		break;
		
		
		case 'C':
		case 'c':
		Toggle_bit(PORTC,pin);
		break;
		
		
		case 'D':
		case 'd':
		Toggle_bit(PORTD,pin);
		break;
	}
}


unsigned char DIO_u8Read_pin(unsigned char port,unsigned char pin)
{
	unsigned char value=0;
	switch(port)
	{
		case 'A':
		case 'a':
		value=Read_bit(PINA,pin);
		break;
		
		case 'b':
		case 'B':
		value=Read_bit(PINB,pin);
		break;
		
		case 'C':
		case 'c':
		value=Read_bit(PINC,pin);
		break;
		
		case 'D':
		case 'd':
		value=Read_bit(PIND,pin);
		break;
		
	}
	return value;
}
void DIO_set_port_direction(unsigned char portname,unsigned char direction)
{
	switch(portname)
	{
		case'a':
		case'A':
		DDRA=direction;
		break;
		
		case 'B':
		case 'b':
		DDRB=direction;
		break;
		
		
		case 'C':
		case 'c':
		DDRC=direction;
		break;
		
		
		case 'D':
		case 'd':
		DDRD=direction;
		break;
	}
}

void DIO_write_port(unsigned char portname,unsigned char value)
{
	switch(portname)
	{
		case 'A' :
		case 'a' :
		PORTA=value; //Write the given value to the port A
		break ;
		
		
			case 'b' :
			case 'B' :
		PORTB=value; //Write the given value to the port B
		break ;
		
		
			case 'C' :
			case 'c' :
		PORTC=value; //Write the given value to the port C
		break ;
		
		
			case 'd' :
			case 'D' :
		PORTD=value; //Write the given value to the port D
		break ;
		
	}
}


unsigned char DIO_u8Read_port(unsigned char portname)
{
	unsigned char return_val=0;
	switch(portname)
	{
		case 'A' :
		case 'a' :
		return_val=PINA; // read the value of port A
		break ;
		case 'B':
		case 'b':
		return_val=PINB; // read the value of port B
		break ;
		case 'C' :
		case 'c' :
		return_val=PINC; // read the value of port C
		break ;
		case 'D':
		case 'd':
		return_val=PIND; // read the value of port D
		break ;
		default:
		break ;
	}
	return return_val;
}


void vToggle_port(unsigned char portname)
{
	
	switch(portname)
	{
		case 'a':
		case 'A':
		PORTA ^=0xff;
		break;
		
		case 'b':
		case 'B':
		PORTB ^=0xff;
		break;
		
		case 'C':
		case 'c':
		PORTC ^=0xff;
		break;
		
	
		case 'd':
		case 'D':
		PORTD ^=0xff;
		break;
		
	}
}

void DIO_vEnable_Internal_PULLUP(unsigned char port,unsigned char pin,unsigned char Enable_Disable)
{
	
	switch(port)
	{
		case 'a':
		case 'A':
			if(Enable_Disable==1)
			{
				Set_bit(PORTA,pin);
			}
		    else
			{
				Clear_bit(PORTA,pin);
			}
			break;
		case 'b':
		case 'B':
			if(Enable_Disable==1)
			{
				Set_bit(PORTB,pin);
			}
			else
			{
				Clear_bit(PORTB,pin);
			}
		
		   break;
		case 'C':
		case 'c':
			if(Enable_Disable==1)
			{
				Set_bit(PORTC,pin);
			}
			else
			{
				Clear_bit(PORTC,pin);
			}
			break;
			
			
		case 'D':
		case 'd':
		if(Enable_Disable==1)
		{
			Set_bit(PORTD,pin);
		}
		else
		{
			Clear_bit(PORTD,pin);
		}	
			break;
	}
	
}
	
	
	void write_low_nibble(unsigned char portname,unsigned char value)
	{
		
		value &=0x0f;
		switch(portname)
		{
			case 'a':
			case 'A':
			PORTA &=0xf0;
			PORTA |=value;
			break;
			
			case 'b':
			case 'B':
			PORTB &=0xf0;
			PORTB |=value;
			break;
			
			case 'c':
			case 'C':
			PORTC &=0xf0;
			PORTC |=value;
			break;
			
			case 'd':
			case 'D':
			PORTD &=0xf0;
			PORTD |=value;
			break;
			
			
			
			
			
			
		}
		
		
	}
	void write_high_nibble(unsigned char portname,unsigned char value)
	{
		
		value=value<<4;
		switch(portname)
		{
			case 'a':
			case 'A':
			PORTA &=0x0F;
			PORTA |=value;
			break;
			
			case 'b':
			case 'B':
			PORTB &=0x0F;
			PORTB |=value;
			break;
			
            case 'c':
            case 'C':
            PORTC &=0x0F;
            PORTC |=value;
            break;
			
			case 'd':
			case 'D':
			PORTD &=0x0F;
			PORTD |=value;
			break;
			
			
			
			
			
			
			
			
			
			
			
			
			
		}
		
		
	}