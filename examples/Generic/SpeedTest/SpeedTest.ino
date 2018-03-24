#include <NintendoExtensionCtrl.h>

ExtensionController controller;  // Generic controller, 6 bytes

const long TestDuration = 1000;  // Length of each test, in milliseconds

void setup() {
	Serial.begin(115200);

	while (!controller.begin()) {
		Serial.println("No controller detected!");
		delay(1000);
	};

	Serial.println("Starting Speed Test...");
}

void loop() {
	boolean validData = true;
	long numUpdates = 0;
	long millisStart = millis();

	while (millis() - millisStart <= TestDuration && validData) {
		validData = controller.update();
		numUpdates++;
	}
	
	if (!validData) {
		Serial.println("ERROR! Invalid data received!");

		while (!controller.reconnect()) {
			Serial.println("Attempting to reconnect...");
			delay(1000);
		}
	}
	else {
		Serial.print("Success! Completed ");
		Serial.print(numUpdates);
		Serial.print(" updates in ");
		Serial.print(TestDuration);
		Serial.println(" milliseconds.");
	}
}

