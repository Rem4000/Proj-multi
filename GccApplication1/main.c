/*
 * GccApplication2.c
 *
 * Created: 2021-02-08 14:09:42
 * Author : nfswt
 */ 
#include <avr/io.h>
#include <util/delay.h>

#include "utils.h"
#include "lcd.h"

void init_can() {
	// CONFIG BROCHES
	DDRA = clear_bits(DDRA, 0b00000011);
	
	// SELECT REF TENSION
	ADMUX = set_bit(ADMUX, REFS1);
	ADMUX = clear_bit(ADMUX, REFS0);
	
	// SELECT FORMAT CONV
	ADMUX = set_bit(ADMUX, ADLAR);
	
	// SELECT FACTEUR DIV HORLOGE (128)
	ADCSRA = set_bits(ADCSRA, 0b00000111);
	
	// ACTIVATION
	ADCSRA = set_bit(ADCSRA, ADEN);
}

char read_analog_input(unsigned char pin) {
	// LIT PA0
	ADMUX = write_bits(ADMUX, 0b00000111, pin);
	
	// start conversion
	ADCSRA = set_bit(ADCSRA, ADSC);
	
	// attendre la fin de la conversion
	while(read_bit(ADCSRA, ADSC));
	
	// retourner valeur
	return ADCH;
}

int main(void)
{
    /* Replace with your application code */
    while (1) 
    {
    }
}

