/************************************************************************************************
*       SEM Tanfolyam 2021
*
* Készítette:   Fábián Bence
* Módosítva:    2021/03/15
* Célja: Atmega32u4 AVR regiszter utasítások használatával LED-et villgotatni várakoztatással
* LED ellenállással a 3-as számú (PD0) lábon
************************************************************************************************/

/*COMPILER OUTPUT:
Sketch uses 246 bytes (0%) of program storage space. Maximum is 28672 bytes.
Global variables use 0 bytes (0%) of dynamic memory, leaving 2560 bytes for local variables. Maximum is 2560 bytes.
*/

#define F_CPU 16000000L
#include <avr/io.h>
#include <avr/delay.h>

int main(void){
    DDRD = 0x01; 
    while (1)
    {
        PORTD = 0x01; 
        _delay_ms(500);
        PORTD = 0;
        _delay_ms(500);
    }
}