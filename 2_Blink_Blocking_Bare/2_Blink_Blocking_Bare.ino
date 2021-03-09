#define F_CPU 16000000L

#include <avr/io.h>
#include <avr/delay.h>

//TO-DO: bit műveletek

//D8 = PB4;
//DDRD 0 = Input, 1 = Output;
//PORTD 0 = Off, 1 = On;
//0b00000000 (bin) =  255 (dec) =  0xFF (hex)
//0b00010000 (bin) =  16 (dec) =   0x10 (hex)
//SZÁMOZÁS 0-tól megy! Bankonként 0-7

int main(void) {
  DDRB = 0x10; 
  PORTB = 0;
  while (1) {
    PORTB = 0x10; 
    _delay_ms(500);
    PORTB = 0;
    _delay_ms(500);
  }
}
