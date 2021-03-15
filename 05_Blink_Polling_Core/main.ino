/************************************************************************************************
*       SEM Tanfolyam 2021
*
* Készítette:   Fábián Bence
* Módosítva:    2021/03/15
* Célja: Atmega32u4 Arduino könyvtár használatával LED-et villgotatni időköz kérdezgetéssel
* LED ellenállással a 3-as számú lábon
************************************************************************************************/

/*Compiler output:
Sketch uses 4284 bytes (14%) of program storage space. Maximum is 28672 bytes.
Global variables use 151 bytes (5%) of dynamic memory, leaving 2409 bytes for local variables. Maximum is 2560 bytes.
*/

unsigned long lastTime = 0;
const long interval = 1000;
int outputState = 0;

void setup(){
    pinMode(3,OUTPUT);
}

void loop(){
    unsigned long currentTime = millis();
    if ( (currentTime - lastTime) >= interval )
    {
        (outputState == LOW)? outputState = HIGH : outputState = LOW;
    }
    digitalWrite(3,outputState);

}