#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>


char digits[] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f};
int number = 30;
	
void blink_thrice() {
	DDRD = 0xff;
	DDRB = 0x03;
	int duration = 0, count = 0;
	while(1) {
		PORTB = 0x01;
		PORTD = digits[0];
		_delay_ms(5);

		PORTB = 0x02;
		PORTD = digits[0];
		_delay_ms(5);
		
		duration++;
		if (duration >= 50) {
			PORTB = 0x00;
			_delay_ms(500);
			duration = 0;
			count++;
		}
		if (count >= 3) {
			return;
		}
	}
}

int main() {
	DDRD = 0xff;
	DDRB = 0x03;

	int time_counter = 0;

	while (1) {
		
		PORTB = 0x01;
		PORTD = digits[number/10];
		_delay_ms(5);

		PORTB = 0x02;
		PORTD = digits[number%10];
		_delay_ms(5);

		time_counter++;

		if (time_counter >= 100) {
			if (number == 0) {
				blink_thrice();
				number = 30;
				} else {
				number--;
			}
			time_counter = 0;
		}
	}
	return 0;
}
