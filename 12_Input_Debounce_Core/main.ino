/************************************************************************************************
*       SEM Tanfolyam 2021
*
* Készítette:   Fábián Bence
* Módosítva:    2021/03/15
* Célja: Atmega32u4 Arduino könyvtár használatával gombal ledet kapcsolni pergésmentesen
* LED ellenállással a 3-as számú lábon; Gomb belső ellenállást használva a 2-es számú lábon
************************************************************************************************/

/*Compiler output:
Sketch uses 4224 bytes (14%) of program storage space. Maximum is 28672 bytes.
Global variables use 159 bytes (6%) of dynamic memory, leaving 2401 bytes for local variables. Maximum is 2560 bytes.
*/
int ledState = HIGH;
int buttonState;             
int lastButtonState = LOW;  

unsigned long lastDebounceTime = 0;  
unsigned long debounceDelay = 50;    

void setup() {
  pinMode(2, INPUT_PULLUP);
  pinMode(3, OUTPUT);

  digitalWrite(3, ledState);
}

void loop() {
    int reading = digitalRead(2);

    if (reading != lastButtonState) {
        lastDebounceTime = millis();
    }

    if ((millis() - lastDebounceTime) > debounceDelay) {
        if (reading != buttonState) {
            buttonState = reading;

            if (buttonState == HIGH) {
                ledState = !ledState;
            }
        }
    }

    digitalWrite(3, ledState);
    lastButtonState = reading;
}
