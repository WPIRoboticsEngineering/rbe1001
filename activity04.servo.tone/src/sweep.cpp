#include <RBE1001Lib.h>
#include <ESP32Servo.h>

// https://wpiroboticsengineering.github.io/RBE1001Lib/classServo.html
Servo servo;
#define SERVO_PIN	14

void setup() 
{
	Serial.begin(115200);
	// pin definitions https://wpiroboticsengineering.github.io/RBE1001Lib/RBE1001Lib_8h.html#define-members
	servo.attach(SERVO_PIN);
}

/*
 * The main loop for the program. The loop function is repeatedly called
 * once the ESP32 is started. 
 */

void loop() 
{
	uint16_t angle = (millis()/20) % 180;
	servo.write(angle);
	Serial.println(angle);
	delay(10);
}
