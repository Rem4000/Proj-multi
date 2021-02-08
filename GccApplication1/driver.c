/*
	 __ ___  __
	|_   |  (_
	|__  |  __)

	MIT License
	
	Coucou

	Copyright (c) 2018	École de technologie supérieure

	Permission is hereby granted, free of charge, to any person obtaining a copy
	of this software and associated documentation files (the "Software"), to deal
	in the Software without restriction, including without limitation the rights
	to use, copy, modify and/or merge copies of the Software, and to permit persons
	to whom the Software is furnished to do so, subject to the following conditions:

	The above copyright notice and this permission notice shall be included in all
	copies or substantial portions of the Software.
*/
/**
	\file
	\brief Code source de fonctions qui pilotent directement du matériel

	\author Noms de membres de l'équipe
	\author idem
	\author idem
	\author idem
	\author idem
	\date date d'aujourd'hui
*/

/* ----------------------------------------------------------------------------
Includes
---------------------------------------------------------------------------- */

#include <avr/io.h>
#include "driver.h"


/* ----------------------------------------------------------------------------
Function definition
---------------------------------------------------------------------------- */

void adc_init(void){

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

uint8_t adc_read(uint8_t canal){

	// 1-Sélection de l'entrée à convertir (canal)
	ADMUX = write_bits(ADMUX, 0b00000111, canal);
	
	// 2-Démarrage d'une conversion
	

	// 3-Attente de la fin de conversion
	

	// 4-Lecture et renvoi du résultat
	
}

void pwm0_init(void){

	// 1-Configuration des broches de sortie (PB4 et PB3)
	// 1.1-Mettre les broches de la modulation de largeur d'impulsion en sortie
	
	
	// 2-Initialisation du TIMER 0
	// 2.1- Mode de comparaison : "Toggle on compare match"
	
	
	// 2.2- Mode du compteur :  "PWM phase correct"
	
	
	// 2.3- Fixer la valeur initiale du compteur 0 à 0
	
	
	// 2.4- Facteur de division de fréquence : 1
	

}

void pwm0_set_PB3(uint8_t duty){

	// Fixer le rapport cyclique à la valeur de duty
	
}


void pwm0_set_PB4(uint8_t duty){

	// Fixer le rapport cyclique à la valeur de duty
	
}

void pwm1_init(uint16_t top){	
	
	// broches de PWM en sortie
	DDRD = set_bit(DDRD, PD4);
	DDRD = set_bit(DDRD, PD5);
	
	//Set OC1A/B on Compare Match when up-counting. Clear OC2A on	Compare Match when down-counting.
	TCCR1A=set_bit(TCCR1A,COM1A1);
	TCCR1A=clear_bit(TCCR1A,COM1A0);
	TCCR1A=set_bit(TCCR1A,COM1B1);
	TCCR1A=clear_bit(TCCR1A,COM1B0);
	
	// Fast PWM mode (avec valeur TOP fixé par ICR1)
	TCCR1B=set_bit(TCCR1B,WGM13);
	TCCR1B=set_bit(TCCR1B,WGM12);
	TCCR1A=set_bit(TCCR1A,WGM11);
	TCCR1A=clear_bit(TCCR1A,WGM10);

	// valeur initiale du compteur à 0
	TCNT1=0;

	// fixer la valeur maximale (TOP) du compteur 2	
	ICR1 = top;			
	
	// activer l'horloge avec facteur de division par 8
	TCCR1B=clear_bit(TCCR1B,CS12);
	TCCR1B=set_bit(TCCR1B,CS11);
	TCCR1B=clear_bit(TCCR1B,CS10);
}

void pwm1_set_PD5(uint16_t limit){
	OCR1A = limit;
}
void pwm1_set_PD4(uint16_t limit){
	OCR1B = limit;
}

void pwm2_init(){
	// broches de PWM en sortie
	DDRD = set_bit(DDRD, PD6);
	DDRD = set_bit(DDRD, PD7);
	
	//Set OC2A/B on Compare Match when up-counting. Clear OC2A on	Compare Match when down-counting.
	
	
	// PWM phase correct
	

	// valeur initiale du compteur à 0
		
		
	// activer l'horloge avec facteur de division de 8
	
}

void pwm2_set_PD7(uint8_t limit){
	// Fixer le rapport cyclique à la valeur de duty
	
}

void pwm2_set_PD6(uint8_t limit){
	// Fixer le rapport cyclique à la valeur de duty
	
}


