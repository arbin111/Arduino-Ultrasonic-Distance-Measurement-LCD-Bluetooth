#include <Arduino.h>

#if 1

#include <SoftwareSerial.h>
#include <LiquidCrystal.h>

// Bluetooth module setup
SoftwareSerial bluetooth(10, 11); // RX, TX

// LCD setup
LiquidCrystal lcd(2,3,4,5,6,12); // RS, EN, D4, D5, D6, D7

const int TRIGGER_PIN = 8; // D8
const int ECHO_PIN = 9; // D9
long Duration=0;

void setup() {
  // put your setup code here, to run once:
  pinMode(TRIGGER_PIN, OUTPUT); // Sets the trigPin as an Output
  pinMode(ECHO_PIN, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600); // Starts the serial communication; Serial output
  bluetooth.begin(9600); // Starts the Bluetooth communication
  lcd.begin(16, 2); // Initializes the LCD display
}

long Distance(long time)
{
  long DistanceCalc; // Variable for the distance result
  DistanceCalc = (time* 0.034) / 2; // Calculating the distance in cm
  return DistanceCalc; // Returns the distance
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(TRIGGER_PIN, LOW); // Sets the trigPin on LOW state
  delayMicroseconds(2); // Delay of 2 microseconds
  digitalWrite(TRIGGER_PIN, HIGH); // Sets the trigPin on HIGH state
  delayMicroseconds(10); // Delay of 10 microseconds
  digitalWrite(TRIGGER_PIN, LOW); // Sets the trigPin on LOW state

  Duration = pulseIn(ECHO_PIN, HIGH); // Reads the echoPin, returns the sound wave travel time in microseconds
  long Distance_cm = Distance(Duration); // Use function to calculate the distance
  Serial.print("Distance= "); // Prints the distance on the Serial Monitor
  Serial.print(Distance_cm);
  Serial.println(" cm");

  // Display the distance on the LCD
  lcd.clear(); // Clears the LCD screen
  lcd.setCursor(0, 0); // Sets the cursor to the top left corner
  lcd.print("Distance:"); // Prints "Distance:" on the first row
  lcd.setCursor(0, 1); // Sets the cursor to the second row
  lcd.print(Distance_cm); // Prints the distance in cm on the second row
  lcd.print("cm"); // Print the unit of measurement

  // Send the distance over Bluetooth
  bluetooth.print("Distance: "); // Sends "Distance: " over Bluetooth
  bluetooth.print(Distance_cm); // Sends the distance in cm over Bluetooth
  bluetooth.println(" cm"); // Sends a new line over Bluetooth
  delay(1000); // Wait for 1 second
  
}


#endif
