/*
 this program calibirate the accuarcy of movement in straight line and gives warning when the object move otherwise.
*/

// defining the pins of the LED, Buzzer and the Laser.
  int laserPin = 3;
  int ledPin=5;
  int buzerPin=2;

void setup() {
  // initialize serial communication at 9600 bits per second:
  // initializing the laser,buzzer and the led as outputs
  pinMode(ledPin,OUTPUT);
  pinMode(laserPin, OUTPUT);
  pinMode(buzerPin,OUTPUT);
  Serial.begin(9600);
  
}


void loop() {

   digitalWrite(laserPin, HIGH); // turn on the laser and keep it on all the time.
  int sensorValue = analogRead(A3);// define the analog read of the ldr sensor to A3 analog pin.
  
  
  if(sensorValue>700){// if the laser hits the ldr sensor
    digitalWrite(ledPin,HIGH);//turn on the LED
    digitalWrite(buzerPin,HIGH);//turn on the buzzer
    
  }else{//if not
    digitalWrite(ledPin,LOW);//turn off the led
    digitalWrite(buzerPin,LOW);//turn off the buzzer.
  }
  Serial.println(sensorValue);//to print the value of the sensor to check for errors
  delay(1000);        // delay in between reads for stability
}
