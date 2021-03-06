/*
*  Project     Nintendo Extension Controller Library
*  @author     David Madison
*  @link       github.com/dmadison/NintendoExtensionCtrl
*  @license    LGPLv3 - Copyright (c) 2018 David Madison
*
*  This file is part of the Nintendo Extension Controller Library.
*
*  This program is free software: you can redistribute it and/or modify
*  it under the terms of the GNU Lesser General Public License as published by
*  the Free Software Foundation, either version 3 of the License, or
*  (at your option) any later version.
*
*  This program is distributed in the hope that it will be useful,
*  but WITHOUT ANY WARRANTY; without even the implied warranty of
*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*  GNU Lesser General Public License for more details.
*
*  You should have received a copy of the GNU Lesser General Public License
*  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*
*  Example:      NES_Demo
*  Description:  Connect to an NES Mini controller and demonstrate all of
*                the avaiable control data functions.
*/

#include <NintendoExtensionCtrl.h>

NESMiniController nes;

void setup() {
	Serial.begin(115200);
	nes.begin();

	while (!nes.connect()) {
		Serial.println("NES Classic Controller not detected!");
		delay(1000);
	}
}

void loop() {
	Serial.println("----- NES Mini Controller Demo -----");  // Making things easier to read
	
	boolean success = nes.update();  // Get new data from the controller

	if (!success) {  // Ruh roh
		Serial.println("Controller disconnected!");
		delay(1000);
	}
	else {
		// Read the DPAD (Up/Down/Left/Right)
		boolean padUp = nes.dpadUp();

		Serial.print("The DPAD up button is ");
		if (padUp == true) {
			Serial.println("pressed");
		}
		else if (padUp == false) {
			Serial.println("released");
		}

		// Read a button (A/B/Start/Select)
		boolean aButton = nes.buttonA();

		Serial.print("The A button is ");
		if (aButton == true) {
			Serial.println("pressed");
		}
		else if (aButton == false) {
			Serial.println("released");
		}

		// Print all the values!
		nes.printDebug();
	}
}
