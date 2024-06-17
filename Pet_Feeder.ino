#include <Servo.h>
#include <SoftwareSerial.h>

Servo myservo;  // create servo object to control a servo
SoftwareSerial bluetooth(2, 3); // RX, TX pins for Bluetooth module

int pos = 0;    // variable to store the servo position
int feedTime = 1000;  // time (in milliseconds) to open the food dispenser

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  bluetooth.begin(9600);  // initialize Bluetooth module with baud rate of 9600
}

void loop() {
  if (bluetooth.available()) {  // if there is data available from the Bluetooth module
    char data = bluetooth.read();  // read the data
    if (data == 'F') {  // if the data is 'F' (for feed)
      myservo.write(180); // set servo to 90 degrees to open the food dispenser
      delay(feedTime);  // wait for specified feed time
      myservo.write(0);  // set servo to 0 degrees to close the food dispenser
      bluetooth.write("Feed completed"); // send confirmation message to Bluetooth module
    }
  }
}