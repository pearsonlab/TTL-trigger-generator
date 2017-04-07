#define DEBUG 1 // change to 1 to debug 
 
 #define THRESHOLD 1.5 // adjust this to control sensitivity in detection of voltage increase
 
 const int outPin = 13; // change output (D) pin number here
 int prev_voltage = 0; // must be initialized to something
 
 void setup() {
  if(DEBUG) {
   // initialize serial communication at 9600 bits per second (to write debugging info back to terminal)
    Serial.begin(9600); 
  }
  // set output pin
  pinMode(outPin, OUTPUT);
  
 }
 
 void loop() {
   // read input on analog pin 0
  int sensorValue = analogRead(A1); // change input (A) pin number here
 // int sensorInput = analogRead(A3); // input from speaker
  // convert analog reading (from 0-1023) to digital
  float voltage = sensorValue * (5.0 / 1023.0);
 
 if(DEBUG) {
    // print value to serial port (view in Tools > Serial Port Monitor)
        Serial.println(voltage);
//    }
    
    // This delays the trigger by
                             // about 6ms so remove before using
                             // during experiments
 }
    // Simplest algorithm ever.  
    if (voltage > prev_voltage + THRESHOLD)
    {
      digitalWrite(outPin, HIGH);
      Serial.println("HIGH...........................................................HIGH");

//delay(100);
    }
    else
    {
     digitalWrite(outPin, LOW); 
//           Serial.println("LOW");
    }
    
   prev_voltage = voltage;
 }
