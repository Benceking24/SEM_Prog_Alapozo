/************************************************************************************************
*       SEM Tanfolyam 2021
*
* Készítette:   Fábián Bence
* Módosítva:    2021/03/15
* Célja: Atmega32u4 Arduino könyvtár használatával gombal ledet kapcsolni
* LED ellenállással a 3-as számú lábon; Gomb belső ellenállást használva a 2-es számú lábon
************************************************************************************************/

/*Compiler output:
Sketch uses 3936 bytes (13%) of program storage space. Maximum is 28672 bytes.
Global variables use 151 bytes (5%) of dynamic memory, leaving 2409 bytes for local variables. Maximum is 2560 bytes.
*/

void setup(){
    pinMode(3, OUTPUT);
    pinMode(2, INPUT_PULLUP);
}

void loop(){
    int inputState = digitalRead(2);
    digitalWrite(3, !inputState);
}