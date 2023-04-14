/*
 * This sketch demonstrates how to use MusiciansMate library to play a track.
 * 
 * 1. Connect a peizo buzzer to pin 17.
 * 2. Upload this sketch to the board.
 */

#include <MusiciansMate.h>


// Connect to a buzzer on digital pin 17
#define BUZZER_PIN 17

// Set default playing tempo to 109 BPM
#define DEFAULT_TEMPO 109

// Define a track
// Every track must be terminated with an element containing all zeros.
track symphony[] = {
    { P_G7,      NOTE_E  },
    { P_G7,      NOTE_E  },
    { P_G7,      NOTE_E  },
    { P_DS7,     NOTE_H  },
    { P_F7,      NOTE_E  },
    { P_F7,      NOTE_E  },
    { P_F7,      NOTE_E  },
    { P_D7,      NOTE_H  },
    { 0, 0 }
};

void setup() {
    Serial.begin(115200);

    // Set buzzer pin mode to OUTPUT
    pinMode(BUZZER_PIN, OUTPUT);

    Serial.println("Done setup");
}

void loop() {
    // Play the track
    playTrack(BUZZER_PIN, symphony, DEFAULT_TEMPO);

    while (true);
}
