/************************************************************************************************
*       SEM Tanfolyam 2021
*
* Készítette:   Fábián Bence
* Módosítva:    2021/03/15
* Célja: Atmega32u4 AVR regiszter utasítások használatával LED-et animálni 8bit-es időzítővel
* LED ellenállással a 3-as számú (PD0) lábon
************************************************************************************************/

/*COMPILER OUTPUT:
Sketch uses 1486 bytes (5%) of program storage space. Maximum is 28672 bytes.
Global variables use 4 bytes (0%) of dynamic memory, leaving 2556 bytes for local variables. Maximum is 2560 bytes.
*/

#define F_CPU 16000000L
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

double dutyCycle = 0;

int main(void){
  DDRD = (1<<PORTD0); //LED kimenet minden más Bemenet
  TCCR0A = (1<<COM0B1)|(1<<WGM00)|(1<<WGM01);
  TIMSK0 = (1<<TOIE0);
  OCR0B = (dutyCycle/100.0)*255;
  sei();
  TCCR0B = (1<<CS00)|(1<<CS02); // elindítja ha beállítjuk
  while(1){
    _delay_ms(10);
    dutyCycle++;
    if(dutyCycle>100){ dutyCycle=0; }
    }
}

ISR(TIMER0_OVF_vect){
    OCR0B = (dutyCycle/100.0)*255; //Futás közbe itt lehetne állítani a dutycycle-t
}
