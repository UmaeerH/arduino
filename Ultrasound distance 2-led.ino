#define echoPin 2
#define trigPin 3
#define outputPin 8 // First LED
#define outputPin2 7 // Second LED

long duration; // Time taken for pulse to reach receiver
int distance; // Variable to store distance calculated, in CM
const int threshold1 = 50; // Const for first threshold, in CM 
const int threshold2 = 25; // Const for second (closer) threshold, in CM

void setup(){
	pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
	pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  pinMode(outputPin, OUTPUT);
  pinMode(outputPin2, OUTPUT);
	Serial.begin(9600);		// baudrate speed
	Serial.println("Distance measurement using Arduino Uno.");
	delay(500);
}

void loop(){
	digitalWrite(trigPin, LOW);
	// 2ms wait to avoid collision
	delayMicroseconds(2);

  	// Turn on trigger for 10ms
	digitalWrite(trigPin, HIGH);
	delayMicroseconds(10);
	digitalWrite(trigPin, LOW);

	// If pulse reached the receiver echoPin set to high
	// Then pulseIn() returns the time taken by the pulse to reach the receiver
	duration = pulseIn(echoPin, HIGH);
	distance = duration * 0.0344 / 2; // Calculate distance using time

	Serial.print("Distance: ");
	Serial.print(distance); // Print the output in serial monitor
	Serial.println(" cm");
  
  	// Threshold to activate buzzer for testing
  	if (distance <= threshold1) {
  		digitalWrite(outputPin, HIGH);
      digitalWrite(outputPin2, LOW);
    	Serial.println("Within threshold");
      if (distance <= threshold2) {
        digitalWrite(outputPin2, HIGH);
        Serial.println("Within threshold2");
      }
      delay(100);
	}
  	else {
   		digitalWrite(outputPin, LOW);
      digitalWrite(outputPin2, LOW);
      delay(100);
	}
}
