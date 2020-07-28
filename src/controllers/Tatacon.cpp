/*
*  Project     Nintendo Extension Controller Library
*  @author     Nullstalgia
*  @link       github.com/dmadison/NintendoExtensionCtrl
*  @license    LGPLv3 - Copyright (c) 2020 Nullstalgia
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
*/

#include "Tatacon.h"

namespace NintendoExtensionCtrl {

constexpr BitMap   Tatacon_Shared::Maps::CenterLeft;
constexpr BitMap   Tatacon_Shared::Maps::CenterRight;

constexpr BitMap   Tatacon_Shared::Maps::RimLeft;
constexpr BitMap   Tatacon_Shared::Maps::RimRight;

boolean Tatacon_Shared::centerLeft() const {
	return getControlBit(Maps::CenterLeft);
}

boolean Tatacon_Shared::centerRight() const {
	return getControlBit(Maps::CenterRight);
}

boolean Tatacon_Shared::rimLeft() const {
	return getControlBit(Maps::RimLeft);
}

boolean Tatacon_Shared::rimRight() const {
	return getControlBit(Maps::RimRight);
}

void Tatacon_Shared::printDebug(Print& output) const {
	char buffer[60];

	char donPrintL = centerLeft() ? 'D' : '-';
	char donPrintR = centerRight() ? 'D' : '-';
	
	char kaPrintL = rimLeft() ? 'K' : '-';
	char kaPrintR = rimRight() ? 'K' : '-';

	output.print("Tatacon - ");
	sprintf(buffer,
            "Center: (Left: %c  Right: %c) | Rim: (Left: %c  Right: %c)",
			donPrintL, donPrintR, kaPrintL, kaPrintR);

	output.println(buffer);
}

}  // End "NintendoExtensionCtrl" namespace
