/************************************************************************************************
*       SEM Tanfolyam 2021
*
* Készítette:   Fábián Bence
* Módosítva:    2021/03/15
* Célja: Atmega32u4 AVR regiszter utasítások használatával LED-et villgotatni 16bit-es időzítővel
* LED ellenállással a 3-as számú (PD0) lábon
************************************************************************************************/

/*COMPILER OUTPUT:
Sketch uses 280 bytes (0%) of program storage space. Maximum is 28672 bytes.
Global variables use 0 bytes (0%) of dynamic memory, leaving 2560 bytes for local variables. Maximum is 2560 bytes.
*/

#define F_CPU 16000000L
#include <avr/io.h>
#include <avr/interrupt.h>

int main(void){
  DDRD = 0x01; //LED kimenet minden más Bemenet
  cli(); //lezárja az interruptokat míg beállítjuk azt
  TCCR1B = (1 <<WGM12); // CTC mód beállítása
  OCR1A=15625; // Határérték
  TIMSK1 = (1<<OCIE1A); // engedélyezi az interrupt vectorját
  sei(); //I-bit in the Status Register ét beállítja
  TCCR1B |= (1 <<CS12) | (1 <<CS10); // Pre-scaler beállítása
  while(1){
    }
}

ISR(TIMER1_COMPA_vect){
      PORTD ^= (1<<PORT0);
}