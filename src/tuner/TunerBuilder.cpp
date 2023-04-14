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

#include "TunerBuilder.h"

#include "GuitarTuner.h"


Tuner *TunerBuilder::build(uint8_t buzzerPin, Instrument type, unsigned long playDuration)
{
    Tuner *tuner;

    switch (type)
    {
        case GUITAR:
            tuner = (Tuner *) new GuitarTuner(buzzerPin, playDuration);
            break;
        default:
            PRINT("Unknown instrument");
    }

    return tuner;
}
