/************************************************************************************************
*       SEM Tanfolyam 2021
*
* Készítette:   Fábián Bence
* Módosítva:    2021/03/15
* Célja: Atmega32u4 AVR regiszter utasítások használatával LED-et villgotatni 8bit-es időzítővel
* LED ellenállással a 3-as számú (PD0) lábon
************************************************************************************************/

/*COMPILER OUTPUT:
Sketch uses 314 bytes (1%) of program storage space. Maximum is 28672 bytes.
Global variables use 2 bytes (0%) of dynamic memory, leaving 2558 bytes for local variables. Maximum is 2560 bytes.
*/

#define F_CPU 16000000L
#include <avr/io.h>
#include <avr/interrupt.h>

int extraTime = 0;

int main(void){
  DDRD = 0x01; //LED kimenet minden más Bemenet
  cli(); //lezárja az interruptokat míg beállítjuk azt
  TCCR0A = (1 <<WGM01); // CTC mód beállítása
  OCR0A=156; // Határérték
  TIMSK0 = (1<<OCIE0A); // engedélyezi az interrupt vectorját
  sei(); //I-bit in the Status Register ét beállítja
  TCCR0B |= (1 <<CS02) | (1 <<CS00); // Pre-scaler beállítása
  while(1){
    }
}


ISR(TIMER0_COMPA_vect){
  extraTime++;
    if(extraTime>100){
      extraTime = 0;
      PORTD ^= (1<<PORT0);
    }
}
