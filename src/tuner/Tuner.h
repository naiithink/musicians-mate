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
 *    the `tuner/' directory.
 * 2. Modify existing source files:
 *    2.1. Add an enum constant depicting the tuner to the `Instrument' enum type
 *         in `Instrument.h'.
 *    2.2. Add a switch-case statement to
 *         `TunerBuilder::build(uint8_t, Instrument, unsigned long)' that catches
 *         the `Instrument' type of the new tuner with value corresponding to enum
 *         constant added through the previous step.
 * 3. Add an include statement including the header of the new tuner
 *    to `MusiciansMate.h' and `TunerBuilder.cpp'.
 * 4. Add all related keywords to `keywords.txt'
 *    4.1. Append to the section 'tuner/Instrument.h', the `Instrument' enum
 *         constant just defined in step <2.1.>.
 *    4.2. Add a new section with the name of the path to your new tuner class
 *         header file, relative to the `/src/' directory.  Then define all
 *         the keywords under that section.
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
