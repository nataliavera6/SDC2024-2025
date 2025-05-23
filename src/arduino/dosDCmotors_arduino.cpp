
#include <Servo.h>

//innecesario para arduino ide, essencial para vscode:
#include <Arduino.h> 


// Motor A connections
int DC_enA = 1;
int DC_in1 = 2;
int DC_in2 = 3;
// Motor B connections
int enB = 3;
int in3 = 5;
int in4 = 4;

void setup() {
	// Set all the motor control pins to outputs
	pinMode(DC_enA, OUTPUT);
	pinMode(enB, OUTPUT);
	pinMode(DC_in1, OUTPUT);
	pinMode(DC_in2, OUTPUT);
	pinMode(in3, OUTPUT);
	pinMode(in4, OUTPUT);
	
	// Turn off motors - Initial state
	// digitalWrite(DC_in1, LOW);
	// digitalWrite(DC_in2, LOW);
	// digitalWrite(in3, LOW);
	// digitalWrite(in4, LOW);
}

// This function lets you control spinning direction of motors
void directionControl() {
	// Set motors to maximum speed
	// For PWM maximum possible values are 0 to 255
	analogWrite(DC_enA, 255);
	analogWrite(enB, 255);

	// Turn on motor A & B
	digitalWrite(DC_in1, HIGH);
	digitalWrite(DC_in2, LOW);
	digitalWrite(in3, HIGH);
	digitalWrite(in4, LOW);
	delay(2000);
	
	// Now change motor directions
	// digitalWrite(DC_in1, LOW);
	// digitalWrite(DC_in2, HIGH);
	// digitalWrite(in3, LOW);
	// digitalWrite(in4, HIGH);
	// delay(2000);
	
	// Turn off motors
	// digitalWrite(DC_in1, LOW);
	// digitalWrite(DC_in2, LOW);
	// digitalWrite(in3, LOW);
	// digitalWrite(in4, LOW);
}

// This function lets you control speed of the motors
void speedControl() {
	// Turn on motors
	digitalWrite(DC_in1, LOW);
	digitalWrite(DC_in2, HIGH);
	digitalWrite(in3, LOW);
	digitalWrite(in4, HIGH);
	
	// Accelerate from zero to maximum speed
	for (int i = 0; i < 256; i++) {
		analogWrite(DC_enA, i);
		analogWrite(enB, i);
		// delay(20);
	}
	
	// Decelerate from maximum speed to zero
	// for (int i = 255; i >= 0; --i) {
	// 	analogWrite(DC_enA, i);
	// 	analogWrite(enB, i);
	// 	// delay(20);
	// }
	
	// Now turn off motors
	// digitalWrite(DC_in1, LOW);
	// digitalWrite(DC_in2, LOW);
	// digitalWrite(in3, LOW);
	// digitalWrite(in4, LOW);
}
void loop() {
	// directionControl();
	// delay(1000);
	speedControl();
	delay(1000);
}

