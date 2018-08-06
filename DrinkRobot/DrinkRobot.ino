/*
 Name:		DrinkRobot.ino
 Created:	8/5/2018 11:16:06 AM
 Author:	jon
*/

// the setup function runs once when you press reset or power the board
//#include <Esplora.h>
//#include <Noritake_VFD_CUY.h>
//#include <CUY_Serial_Sync.h>
//#include <CUY_Serial_Async.h>
//#include <CUY_Parallel.h>
//#include <CUY_Interface.h>
//#include <avr\io.h>
//#include <avr\interrupt.h>

volatile unsigned int encoder_count = 0;
const byte interruptPin = 32;
const byte motorPin = 33;
unsigned int encoder_count_old = 0;
int i = 0;

void countEncoder();

void setup() {
	Serial.begin(115200);
	pinMode(motorPin, OUTPUT);
	pinMode(13, OUTPUT);
	pinMode(interruptPin, INPUT_PULLUP);
	attachInterrupt(digitalPinToInterrupt(interruptPin), countEncoder, CHANGE);

}

// the loop function runs over and over again until power down or reset
void loop() {
	while (encoder_count_old <= 50){
		//Serial.println(encoder_count_old);
		if (i == 1) {
			Serial.print("count: ");
			Serial.println(encoder_count_old);
			i = 0;
		}
		delay(10);
		digitalWrite(13, LOW);
		digitalWrite(motorPin, HIGH);

	}
		digitalWrite(motorPin, LOW);
		encoder_count_old = 0;
		encoder_count = 0;
		Serial.println("Value Reset");
		delay(1000);
}

void countEncoder() {
	encoder_count++;
	encoder_count_old = encoder_count;
	i++;
	digitalWrite(13, HIGH);
}