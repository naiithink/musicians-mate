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

/*
 * ADDING A NEW TUNER
 * ==================
 * 
 * 1. Implement a new tuner class that inherits the `Tuner' class, place it in
 *    the `tuners/' directory.
 * 2. Modify `Tuner.h':
 *  2.1. Add an enum constant depicting the tuner to the `instrument' enum type
 *       in `Tuner.h'.
 *  2.2. Add a switch-case statement to
 *       `TunerBuilder::build(uint8_t, instrument, unsigned long)' that catches
 *       the `instrument' type of the new tuner with value corresponding to enum
 *       constant added through the previous step.
 * 3. Add an include statement including the header of the new tuner
 *    to `MusiciansMate.h' and `Tuner.cpp'
 */


#ifndef TUNER_H
#define TUNER_H


#include <stdint.h>

#include "Instrument.h"


class Tuner
{
public:
    virtual bool playPitch(const int) = 0;

protected:
    explicit Tuner(uint8_t, unsigned long);

    uint8_t buzzerPin;

    Instrument type;

    int pitchCount;

    unsigned long playDuration;

    int *pitches;
};


#endif /* TUNER_H */
