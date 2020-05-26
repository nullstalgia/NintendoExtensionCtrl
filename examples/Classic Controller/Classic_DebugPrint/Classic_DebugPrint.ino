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
*  Example:      Classic_DebugPrint
*  Description:  Connect to a Classic Controller and continuously print
*                its control data, nicely formatted for debugging, over
*                the serial bus.
*/

#include <NintendoExtensionCtrl.h>

ClassicController classic;

void setup() {
	Serial.begin(115200);
	classic.begin();

	while (!classic.connect()) {
		Serial.println("Classic Controller not detected!");
		delay(1000);
	}

	//classic.setHighRes(true);  // uncomment to run in high resolution mode
}

void loop() {
	boolean success = classic.update();  // Get new data from the controller

	if (success == true) {  // We've got data!
		classic.printDebug();  // Print all of the values!
	}
	else {  // Data is bad :(
		Serial.println("Controller Disconnected!");
		delay(1000);
		classic.connect();
	}
}
