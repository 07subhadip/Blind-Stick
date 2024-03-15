const int pinNumber = 3;

void setup() {
  pinMode(pinNumber, OUTPUT);
}

void loop() {
  tone(pinNumber, 1000); // Play a tone at 1 kHz frequency
  delay(500);             // Wait for 0.5 seconds
  noTone(pinNumber);      // Stop the tone
  delay(500);             // Wait for 0.5 seconds
}