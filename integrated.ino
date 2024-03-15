#include <SoftwareSerial.h>
#include "TFMini.h"
TFMini tfmini;

const int pinNumber = 3;

// Adjust these pin numbers to the pins connected to the TFMini
SoftwareSerial SerialTFMini(2,1); // RX, TX for ESP8266 (e.g., NodeMCU or Wemos D1 Mini)

void getTFminiData(int* distance, int* strength) {
  static char i = 0;
  char j = 0;
  int checksum = 0;
  static int rx[9];
  if (SerialTFMini.available()) {
    rx[i] = SerialTFMini.read();
    if (rx[0] != 0x59) {
      i = 0;
    } else if (i == 1 && rx[1] != 0x59) {
      i = 0;
    } else if (i == 8) {
      for (j = 0; j < 8; j++) {
        checksum += rx[j];
      }
      if (rx[8] == (checksum % 256)) {
        *distance = rx[2] + rx[3] * 256;
        *strength = rx[4] + rx[5] * 256;
      }
      i = 0;
    } else {
      i++;
    }
  }
}

void setup() {
    Serial.begin(115200); // Initialize hardware serial port (serial debug port)
    Serial.println("Initializing...");
    SerialTFMini.begin(115200); // Assuming TFMINI_BAUDRATE is 115200
    tfmini.begin(&SerialTFMini); // Initialize the TF Mini sensor

    pinMode(pinNumber, OUTPUT);

}

void loop() {
    int distance = 0;
    int strength = 0;

    getTFminiData(&distance, &strength);
    while (!distance) {
    getTFminiData(&distance, &strength);
    if (distance) {
        Serial.print(distance);
        Serial.print("cm\t");
        Serial.print("strength: ");
        Serial.println(strength);
    }
    }
    delay(100);
    if(distance<=20){
        tone(pinNumber, 500); // Play a tone at 1 kHz frequency
        delay(1000);             // Wait for 0.5 seconds
        noTone(pinNumber);      // Stop the tone
        delay(1000); 
    }
    else if(distance>20 && distance <50){
        tone(pinNumber, 2000); // Play a tone at 1 kHz frequency
        delay(750);             // Wait for 0.5 seconds
        noTone(pinNumber);      // Stop the tone
        delay(750); 
    }
    else if(distance>=50 && distance<100){
      tone(pinNumber,4000);
      delay(500);
      noTone(pinNumber);
      delay(500);
    }
    
}
//  THIS WORKS