Ultrasonic Distance Sensor with Arduino and Bluetooth Communication
This project demonstrates how to use an ultrasonic distance sensor with an Arduino board and establish Bluetooth communication with a mobile device. In this case, we will write our code in VS Code.
Hardware Required
* Arduino board Nano (or any other like Uno.)
* HC-SR04 Ultrasonic Sensor
* Bluetooth module (HC-05 or HC-06)
* LCD display (16x2)
* Jumper wires
Software Required
* Arduino IDE
* Visual Studio Code
* PlatformIO extension for VS Code
* Bluetooth Terminal HC-05 app (Android) or any other.
Setting up the Hardware
1. Connect the HC-SR04 ultrasonic sensor to the Arduino board as follows:
* VCC to 5V
* Trig to D8
* Echo to D9
* GND to GND
2. Connect the Bluetooth module to the Arduino board as follows:
* VCC to 5V
* GND to GND
* TX to D11
* RX to D10
3. Connect the LCD display to the Arduino board as follows:
* VSS to GND
* VDD to 5V
* VO to 10K potentiometer
* RS to D2
* RW to GND
* EN to D3
* D4 to D4
* D5 to D5
* D6 to D6
* D7 to D12
Setting up the Software
1. Install the latest version of the Arduino IDE from the official website.
2. Install Visual Studio Code from the official website.
3. Open Visual Studio Code and install the PlatformIO extension by going to the Extensions tab and searching for "PlatformIO".
4. Create a new PlatformIO project and select the Arduino board you are using.
5. Copy and paste the above code into the main.cpp file of your PlatformIO project.
6. Build and upload the code to your Arduino board using the PlatformIO toolbar in Visual Studio Code.
7. Install the Bluetooth Terminal HC-05 app on your Android device from the Google Play Store.
Running the Project
1. Connect the Arduino board to your computer via USB.
2. Open the Serial Monitor in the Arduino IDE or the PlatformIO toolbar in Visual Studio Code to view the distance readings.
3. Open the Bluetooth Terminal HC-05 app on your Android device.
4. Pair your device with the Bluetooth module using the app.
5. Once paired, you should see the distance readings displayed on the app as well as on the LCD screen in real-time.

