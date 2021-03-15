/************************************************************************************************
*       SEM Tanfolyam 2021
*
* Készítette:   Fábián Bence
* Módosítva:    2021/03/15
* Célja: Atmega32u4 AVR regiszter utasítások használatával LED-et animálni potméter állása alapján
* LED ellenállással a 3-as számú (PD0) lábon; Potméter A2 (PF5) számú lábon
************************************************************************************************/

/*COMPILER OUTPUT:
Sketch uses 770 bytes (2%) of program storage space. Maximum is 28672 bytes.
Global variables use 4 bytes (0%) of dynamic memory, leaving 2556 bytes for local variables. Maximum is 2560 bytes.
*/

#define F_CPU 16000000L
#include <avr/io.h>
#include <avr/interrupt.h>

double dutyCycle = 0;

void setupADC(){
  ADMUX = (1<<REFS0) |(1<<MUX0)|(1<<MUX2);
  ADCSRA = (1<<ADEN)|(1<<ADIE)|(1<<ADPS0)|(1<<ADPS1)|(1<<ADPS2);
  DIDR0 = (1<<ADC5D);

  startADC();
}

void startADC(){
  ADCSRA |= (1<<ADSC);  
}

int main(void){
  DDRD = (1<<PORTD0); //LED kimenet minden más Bemenet
  TCCR0A = (1<<COM0B1)|(1<<WGM00)|(1<<WGM01);
  TIMSK0 = (1<<TOIE0);
  setupADC();
  sei();
  TCCR0B = (1<<CS00)|(1<<CS02); // elindítja ha beállítjuk
  while(1){
    }
}

ISR(TIMER0_OVF_vect){
    OCR0B = dutyCycle; //Futás közbe itt lehetne állítani a dutycycle-t
}

ISR(ADC_vect){
  dutyCycle = ADC/4; //10bit -> 8bit
  startADC();
}
