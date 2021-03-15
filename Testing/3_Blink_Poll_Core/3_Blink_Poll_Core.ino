unsigned long lastTime = 0;
const int interval = 500; //max 596 óra
int state = LOW;

void setup() {
  pinMode(8, OUTPUT);    
}

void loop(){
   unsigned long currentTime = millis(); 
   if( currentTime - lastTime > interval){
      lastTime = currentTime;
      state=(state)?0:1;
      digitalWrite(8, state);
    }
}
