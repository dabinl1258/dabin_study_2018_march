/*
show number in segment At regular intervals
0 1 3 ... 9 0 .. 1 2 3 .. 9 ...
atmega328
*/

#define F_CPU 16000000L

#include <avr/io.h>
#include <util/delay.h>

void delay(int);

int main(void)
{
	short numberToBCD[]  = {0x40,0x79 , 0x24,0x30, 0x19, 0x12 , 0x03 , 0x58 ,0x00,0x18};
	int current_state = 0;
	DDRB = 0xff;
	while(1)
	{


		PORTB = numberToBCD[current_state];
		//PORTB = numberToBCD[2];

		delay(30);
		current_state = (current_state + 1) % 10;
	}

	return 0;
}

void delay(int d) // d : ms
{
	static int i;
	for ( i = 0 ; i <= d; i++) _delay_ms(1);
}
