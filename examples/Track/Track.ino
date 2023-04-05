/*
 * This sketch demonstrates how to use MusiciansMate library to play a track.
 * 
 * 1. Connect a peizo buzzer to pin 17.
 * 2. Upload this sketch to the board.
 */

#include <MusiciansMate.h>

// This header file contains all the macro definitions for pitches and their frequencies
#include "Pitches.h"


// Connect to a buzzer on digital pin 17
#define BUZZER_PIN 17

// Set default playing tempo to 109 BPM
#define DEFAULT_TEMPO 109

// Set the quarter note duration,
// this track is supposed to be played in Legato -- the articulation.
#define QNOTE_DURATION (1000 * 1 * 0.6)

// Define a track
// Every track must be terminated with an element containing all zeros.
track symphony[] = {
    { NOTE_G7,      QNOTE_DURATION / 4  },
    { NOTE_G7,      QNOTE_DURATION / 4  },
    { NOTE_G7,      QNOTE_DURATION / 4  },
    { NOTE_DS7,     QNOTE_DURATION * 2  },
    { NOTE_F7,      QNOTE_DURATION / 4  },
    { NOTE_F7,      QNOTE_DURATION / 4  },
    { NOTE_F7,      QNOTE_DURATION / 4  },
    { NOTE_D7,      QNOTE_DURATION * 2  },
    { 0, 0 }
};

void setup() {
    Serial.begin(115200);

    // Set buzzer pin mode to OUTPUT
    pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
    // Play the track
    playTrack(BUZZER_PIN, symphony, DEFAULT_TEMPO);

    while (true);
}
