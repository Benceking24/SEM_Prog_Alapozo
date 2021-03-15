/************************************************************************************************
*       SEM Tanfolyam 2021
*
* Készítette:   Fábián Bence
* Módosítva:    2021/03/15
* Célja: Atmega32u4 Arduino könyvtár használatával UART üzenetet küldeni
* UART-USB interface csatlakoztatva a TX0 tűhöz
************************************************************************************************/

/*Compiler output:
Sketch uses 4410 bytes (15%) of program storage space. Maximum is 28672 bytes.
Global variables use 336 bytes (13%) of dynamic memory, leaving 2224 bytes for local variables. Maximum is 2560 bytes.
*/



void setup(){
    Serial1.begin(9600);
}

void loop(){
    Serial1.write("Hello world!");
}