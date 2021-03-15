/************************************************************************************************
*       SEM Tanfolyam 2021
*
* Készítette:   Fábián Bence
* Módosítva:    2021/03/15
* Célja: Atmega32u4 AVR regiszter utasítások használatával gombal LED-et kapcsolni
* LED ellenállással a 3-as számú (PD0) lábon; Gomb belső ellenállást használva a 2-es számú (PD1) lábon
************************************************************************************************/

/*COMPILER OUTPUT:
Sketch uses 222 bytes (0%) of program storage space. Maximum is 28672 bytes.
Global variables use 0 bytes (0%) of dynamic memory, leaving 2560 bytes for local variables. Maximum is 2560 bytes.
*/

#define F_CPU 16000000L
#include <avr/io.h>

int main(void){
  DDRD = 0x01; //LED kimenet minden más Bemenet
  PORTD = 0x02; //LED kikapcsol és Pullup
  while(1){
    if(!(PIND & 0x02)){ //Maszkolás
      PORTD = 0x03;
    }
    else{
      PORTD = 0x02;
    }
  }
}