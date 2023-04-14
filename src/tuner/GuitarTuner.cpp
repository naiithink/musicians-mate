/*
 * Epic IoT's implementation of MusiciansMate Arduino library in C++
 * Copyright (C) 2023 The Epic IoT Team
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */


#include <Arduino.h>

#include "../utils/Utils.h"
#include "../utils/Pitches.h"

#include "GuitarTuner.h"


GuitarTuner::GuitarTuner(uint8_t buzzerPin, unsigned long playDuration)
: Tuner::Tuner(buzzerPin, playDuration)
{
    this->buzzerPin = buzzerPin;
    this->type = GUITAR;
    this->pitchCount = 6;
    this->playDuration = playDuration;
    this->pitches = new int[pitchCount] {
        P_E2,
        P_A2,
        P_D3,
        P_G3,
        P_B3,
        P_E4
    };
}


bool GuitarTuner::playPitch(const int index)
{
    PRINT("Playing pitch");

    if (index < 0 || index > pitchCount)
    {
        PRINT("Pitch index out of range");
        return false;
    }

    tone(buzzerPin, pitches[index], playDuration);
    delay(playDuration);

    PRINT("Done playing pitch");

    noTone(buzzerPin);

    return true;
}
