# Blind Stick

Blind Stick is a project that includes a variety of components. Below are details about one of its main components, TFMINI with Arduino.

## TFMINI with Arduino

TFMINI is a sensor often used in projects like Blind Stick. Here's how to connect TFMINI with Arduino UNO R3:

1. **TX (Data Out) - PIN 2 (Green):** Connect the green wire from TFMINI to PIN 2 on Arduino.
2. **RX (Data In) - PIN 1 (White):** Connect the white wire from TFMINI to PIN 1 on Arduino.
3. **GND (Ground) - Black:** Connect the black wire from TFMINI to the ground (GND) on Arduino.
4. **VCC (Power) - Red:** Connect the red wire from TFMINI to the 5V power source on Arduino.

This configuration establishes communication between the TFMINI Lidar sensor and the Arduino UNO R3.


## MPU6050 with Arduino

1. **SDA - PIN A4:** Connect the SDA of MPU6050 to PIN A4 on Arduino.
2. **SCL - PIN A5:** Connect the SCL of MPU6050 to PIN A5 on Arduino.
3. **VCC(5V):** Connect the VCC PIN to 5V Arduino PIN.
4. **GND:** Connect the GND PIN to GND Arduino PIN.

## BUZZER with Arduino

1. **GND (Black):** Connect the GND PIN to GND Arduino PIN.
2. **VCC (Red) - PIN~3:** Connect the VCC to PIN~3 on Arduino.

## TFMini and Buzzer Integration

1. Adding the Buzzer code snippets at the end of the TFMini code pallate.
2. Integration of the PIN remain same as the previous.


## WORK TO BE DONE

1. Adding a Wheel with the Servo Motor to change the path direction according to the Obstacle detection.
