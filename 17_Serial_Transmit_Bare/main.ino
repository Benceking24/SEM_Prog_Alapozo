/************************************************************************************************
*       SEM Tanfolyam 2021
*
* Készítette:   Fábián Bence
* Módosítva:    2021/03/15
* Célja: Atmega32u4 AVR regiszter utasítások használatával UART üzenetet küldeni
* UART-USB interface csatlakoztatva a TX0 tűhöz (Serial1)
************************************************************************************************/

/*COMPILER OUTPUT:
Sketch uses 342 bytes (1%) of program storage space. Maximum is 28672 bytes.
Global variables use 0 bytes (0%) of dynamic memory, leaving 2560 bytes for local variables. Maximum is 2560 bytes.
*/

#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/delay.h>

#define F_CPU 16000000L
#define BUAD 9600
#define BRC ((F_CPU / 16 / BUAD) - 1)

int main(void){
    UBRR1H = (BRC >> 8);
    UBRR1L = BRC;

    UCSR1B = (1 << TXEN1);
    UCSR1C = (1 << UCSZ11) | (1 << UCSZ10);

  while(1){
    UDR1 = 'H';
    _delay_ms(100);
    UDR1 = 'E';
    _delay_ms(100);
    UDR1 = 'L';
    _delay_ms(100);
    UDR1 = 'L';
    _delay_ms(100);
    UDR1 = 'O';
    _delay_ms(3000);
    }
}
