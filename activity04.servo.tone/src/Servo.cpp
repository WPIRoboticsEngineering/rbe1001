#include <RBE1001Lib.h>
#include <ESP32Servo.h>

// https://wpiroboticsengineering.github.io/RBE1001Lib/classServo.html
Servo doorLock;
#define SERVO_LOCK_PIN	25

void setup() 
{
	Serial.begin(115200);
	// pin definitions https://wpiroboticsengineering.github.io/RBE1001Lib/RBE1001Lib_8h.html#define-members
	doorLock.attach(SERVO_LOCK_PIN);
	doorLock.write(0);
}

/*
 * The main loop for the program. The loop function is repeatedly called
 * once the ESP32 is started. 
 */

void loop() 
{
	uint16_t angle = (millis()/20) % 180;
	doorLock.write(angle);
	Serial.println(angle);
	delay(10);
}
