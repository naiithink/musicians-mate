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


#ifndef TUNER_BUILDER_H
#define TUNER_BUILDER_H


#include <stdint.h>

#include "Tuner.h"


class TunerBuilder
{
public:
    static Tuner *build(uint8_t, Instrument, unsigned long);

private:
    TunerBuilder();
};


#endif /* TUNER_BUILDER_H */
