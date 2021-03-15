/************************************************************************************************
*       SEM Tanfolyam 2021
*
* Készítette:   Fábián Bence
* Módosítva:    2021/03/15
* Célja: Atmega32u4 Arduino könyvtár használatával LED-et animálni
* LED ellenállással a 3-as számú lábon
************************************************************************************************/

/*Compiler output:
Sketch uses 3936 bytes (13%) of program storage space. Maximum is 28672 bytes.
Global variables use 151 bytes (5%) of dynamic memory, leaving 2409 bytes for local variables. Maximum is 2560 bytes.
*/

int dutyCycle = 0;

void setup(){
    pinMode(3,OUTPUT);
}

void loop(){
    delay(10);
    dutyCycle++;
    if (dutyCycle>100)
    {
        dutyCycle = 0;
    }
    analogWrite(3,dutyCycle);
}