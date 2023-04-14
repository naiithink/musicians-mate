/*
 * This sketch demonstrates how to use MusiciansMate library to build a simple Guitar tuner.
 * 
 * 1. Connect a peizo buzzer to pin 17.
 * 2. Connect an XY joystick's SW to pin 16.
 * 3. Upload this sketch to the board.
 * 
 * To play selected string sound, push the joystick down once.
 * To switch the string, move the joystick in x-direction, also check the current string on serial monitor.
 */

#include <MusiciansMate.h>


// Connect to a buzzer on digital pin 17
#define BUZZER_PIN 17

// Connect to an XY joystick's SW on digital pin 16
#define JOYSTICK_PIN 16

// String pitch playing duration
#define TUNER_DURATION (1000)

// Joystick push button debouncing period
#define DEBOUNCE_DELAY (unsigned long) 50


// Current state of the joystick
int joystickState;

// Prior joystick state -- debouncing
int lastJoystickState = 1;

// Prior joystick state change time -- debouncing
unsigned long lastJoystickDebounceTime = millis();

// Guitar string index ranged from 0 to 5
int currentString = 0;

// Construct a GuitarTuner instance
GuitarTuner *guitarTuner = (GuitarTuner *) TunerBuilder::build(BUZZER_PIN, GUITAR, TUNER_DURATION);


void setup()
{
    Serial.begin(115200);

    pinMode(BUZZER_PIN, OUTPUT);
    pinMode(JOYSTICK_PIN, INPUT_PULLUP);
}


void loop()
{
    uint16_t joystickX = analogRead(A0);
    uint16_t joystickY = analogRead(A3);

    // Joystick was moved to the left
    if (joystickX == 0)
    {
        shiftStringDown();
        delay(300);
    }
    // Joystick was moved to the right
    else if (joystickX >= 4000)
    {
        shiftStringUp();
        delay(300);
    }

    // Debouncing with delay period
    if ((millis() - lastJoystickDebounceTime) >= DEBOUNCE_DELAY)
    {
        joystickState = digitalRead(JOYSTICK_PIN);

        if (joystickState != lastJoystickState)
        {
            lastJoystickDebounceTime = millis();
            lastJoystickState = joystickState;

            // If the joystick button is pressed, play the selected string sound
            if (joystickState == 1)
                guitarTuner->playPitch(currentString);
        }
    }
}


// Shift string up
void shiftStringUp()
{
    if (currentString < 5)
        currentString++;

    Serial.printf("String: %d\n", currentString);
}


// Shift string down
void shiftStringDown()
{
    if (currentString > 0)
        currentString--;

    Serial.printf("String: %d\n", currentString);
}
