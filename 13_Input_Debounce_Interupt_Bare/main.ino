/************************************************************************************************
*       SEM Tanfolyam 2021
*
* Készítette:   Fábián Bence
* Módosítva:    2021/03/15
* Célja: Atmega32u4 AVR regiszter utasítások használatával gombal LED-et kapcsolni pergésmentesen
* LED ellenállással a 3-as számú (PD0) lábon; Gomb belső ellenállást használva a 2-es számú (PD1) lábon
************************************************************************************************/

/*COMPILER OUTPUT:
Sketch uses 322 bytes (1%) of program storage space. Maximum is 28672 bytes.
Global variables use 2 bytes (0%) of dynamic memory, leaving 2558 bytes for local variables. Maximum is 2560 bytes.
*/

#define F_CPU 16000000L
#include <avr/io.h>
#include <avr/delay.h>
#include <avr/interrupt.h>

int cliFlag = 0;

int main(void){
  DDRD = (1 << PORTD0); //LED kimenet minden más Bemenet
  PORTD = (1 << PORTD1) | (1 << PORTD0); //LED kikapcsol és Pullup
  EIMSK = (1 << INT1);
  while(1){
    if(cliFlag == 0){
      sei();
    }
    else{
      cli();
      _delay_ms(2000);
      cliFlag = 0;
    }
  }
}

ISR(INT1_vect){
  PORTD ^= (1 << PORTD0);
  cliFlag = 1;
}