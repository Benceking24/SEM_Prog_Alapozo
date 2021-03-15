/************************************************************************************************
*       SEM Tanfolyam 2021
*
* Készítette:   Fábián Bence
* Módosítva:    2021/03/15
* Célja: Atmega32u4 Arduino könyvtár használatával LED-et animálni a potméter állása alapján
* LED ellenállással a 3-as számú lábon, Potméter az 20-as (A2) számú lábon
************************************************************************************************/

/*Compiler output:
Sketch uses 4314 bytes (15%) of program storage space. Maximum is 28672 bytes.
Global variables use 149 bytes (5%) of dynamic memory, leaving 2411 bytes for local variables. Maximum is 2560 bytes.
*/

int dutyCycle = 0;

void setup(){
    pinMode(3,OUTPUT);
    pinMode(20, INPUT);
}

void loop(){
    dutyCycle = analogRead(20)/4;
    analogWrite(3,dutyCycle);
}