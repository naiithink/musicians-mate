/*
 * This sketch demonstrates how to use MusiciansMate library to build a multi-core metronome.
 * 
 * 1. Connect a peizo buzzer to pin 17.
 * 2. Connect an XY joystick's SW to pin 16.
 * 3. Upload this sketch to the board.
 * 
 * To play or pause the metronome, push the joystick down once.
 * To adjust the metronome tempo, move the joystick in x-direction -- left (decrease) or right (increase).
 */

#include <MusiciansMate.h>

// This header file contains all the macro definitions for pitches and their frequencies
#include "Pitches.h"


// Connect to a buzzer on digital pin 17
#define BUZZER_PIN 17

// Connect to an XY joystick's SW on digital pin 16
#define JOYSTICK_PIN 16

// Set default playing tempo to 120 BPM
#define DEFAULT_TEMPO 120

// Set the quarter note duration
#define QNOTE_DURATION (1000 * 1 * 0.18)

// Set the metronome ticks duration
#define TUNER_DURATION (1000)

// Joystick push button debouncing period
#define DEBOUNCE_DELAY (unsigned long) 50


// Task handle for backgroud task
TaskHandle_t BackgroundTask;

// Current state of the joystick
int joystickState;

// Prior joystick state -- debouncing
int lastJoystickState = 1;

// Prior joystick state change time -- debouncing
unsigned long lastJoystickDebounceTime = millis();

// Current metronome state
//  -1: paused
//   1: playing
int metronomeState = -1;

// Construct a Metronome instance
Metronome *metronome = new Metronome(BUZZER_PIN, NOTE_F7, QNOTE_DURATION, DEFAULT_TEMPO);


// This function runs on core #1
void setup()
{
    Serial.begin(115200);

    pinMode(BUZZER_PIN, OUTPUT);
    pinMode(JOYSTICK_PIN, INPUT_PULLUP);

    // Allocate CPU core for the `backgroundTask' function
    xTaskCreatePinnedToCore(
        backgroundTask,
        "backgroundTask",
        2048,
        NULL,
        1,
        &BackgroundTask,
        0
    );

    // Initialize the current metronome state
    metronomeState = metronome->getIsPlaying() == true ? 1
                                                       : -1;
}


// This function runs on core #0
void backgroundTask(void *param)
{
    while (true)
    {
        // Add some delay to each loop
        vTaskDelay(10);

        // Start the metronome if it has been paused and the current metronome state is set to 1
        if (metronome->getIsPlaying() == false && metronomeState == 1)
            metronome->start();
    }
}


// This function runs on core #1
void loop()
{
    uint16_t joystickX = analogRead(A0);
    uint16_t joystickY = analogRead(A3);

    // If the metronome is currently playing
    if (metronome->getIsPlaying() == true)
    {
        // Joystick was moved to the left
        if (joystickX == 0)
            decreaseMetronomeTempo();
        // Joystick was moved to the right
        else if (joystickX >= 4000)
            increaseMetronomeTempo();
    }

    // Debouncing with delay period
    if ((millis() - lastJoystickDebounceTime) >= DEBOUNCE_DELAY)
    {
        joystickState = digitalRead(JOYSTICK_PIN);

        if (joystickState != lastJoystickState)
        {
            lastJoystickDebounceTime = millis();
            lastJoystickState = joystickState;

            // If the joystick button is pressed, toggle the current metronome state (play/pause)
            if (joystickState == 1)
                toggleMetronomeState();
        }
    }
}


// This function gets called each time the metronome 'tick'
// Return false to stop.
bool metronomeStopObserver()
{
    if (metronomeState > 0)
        return true;
    else
        return false;
}


// Toggle the current metronome state
void toggleMetronomeState()
{
    metronomeState *= -1;
    Serial.println(metronomeState);
}


// Increase the metronome tempo by 1
void increaseMetronomeTempo()
{
    metronome->setTempo(metronome->getTempo() + 1);
    delay(300);
    Serial.printf("Metronome tempo ++: %d\n", metronome->getTempo());
}


// Decrease the metronome tempo by 1
void decreaseMetronomeTempo()
{
    metronome->setTempo(metronome->getTempo() - 1);
    delay(300);
    Serial.printf("Metronome tempo --: %d\n", metronome->getTempo());
}
