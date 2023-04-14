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
#include "../utils/Notes.h"

#include "Track.h"


void playTrack(uint8_t buzzerPin, track *piece, uint32_t tempo)
{
    PRINT("Playing track");

    double tempoDelay = SEC_IN_MILLI / tempo;
    double relativeDelay = 0.0;
    track *head = piece;

    while (head->pitch != PIECE_TERMINATOR && head->relativeDuration != PIECE_TERMINATOR)
    {
        relativeDelay = tempoDelay * head->relativeDuration;
        tone(buzzerPin, head->pitch, relativeDelay);
        delay(relativeDelay);

        head++;
    }

    noTone(buzzerPin);

    PRINT("Done playing track");
}
