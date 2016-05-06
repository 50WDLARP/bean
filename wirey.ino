#include <Wire.h>
int i = 0;
void requestEvent() {
    Wire.write(i);
    i = 0;
}
int b = 0;
void receiveEvent(int howmany) {
    b = Wire.read();
}

void setup() {
  // put your setup code here, to run once:
  Wire.begin(1);
  Wire.onRequest(requestEvent);
  Wire.onReceive(receiveEvent);
  pinMode(5, INPUT);
}
void loop() {
    while(Serial.available()) {
        char incomingByte = Serial.read();

        if (incomingByte == 'T') {
            i = 10;
        }

        if (incomingByte == 'N') {
            i = 20;
        }
    }
    if (digitalRead(5)) {
        i = 1;
        Bean.setLed(b, b, b);
    } else {
    }

    // put your main code here, to run repeatedly:
    delay(100);
}
