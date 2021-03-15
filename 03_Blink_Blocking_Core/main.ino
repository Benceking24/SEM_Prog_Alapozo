/************************************************************************************************
*       SEM Tanfolyam 2021
*
* Készítette:   Fábián Bence
* Módosítva:    2021/03/15
* Célja: Atmega32u4 Arduino könyvtár használatával LED-et villgotatni várakoztatással
* LED ellenállással a 3-as számú lábon
************************************************************************************************/

/*Compiler output:
Sketch uses 3954 bytes (13%) of program storage space. Maximum is 28672 bytes.
Global variables use 149 bytes (5%) of dynamic memory, leaving 2411 bytes for local variables. Maximum is 2560 bytes.
*/

void setup(){
    pinMode(3,OUTPUT);
}

void loop(){
    digitalWrite(3,HIGH);
    delay(1000);
    digitalWrite(3,LOW);
    delay(1000);
}