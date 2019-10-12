#pragma  once

#include "melody.h"
#include "picthes.h"

#define BUZZER_NOTE_DURATION 125

class Buzzer
{
public:
    Buzzer(int _pin, int _numBuzzer, int _countMelody)
    {
        pin = _pin;
        pinMode(pin, OUTPUT);

        numBuzzer = _numBuzzer;      
        countMelody = _countMelody;
        melodis = new Melody[countMelody];
        
        noteStartedMs = 0;
        currentMelody = 0;
    }

    void setMelody(Melody _melody, int numMelody)
    {
        melodis[numMelody] = _melody;
    }

    void setNextMelody(){
        melodis[currentMelody].resetMelody();
        currentMelody = (currentMelody + 1) % countMelody;
    }

    void playSound()
    {
        if ((millis() - noteStartedMs) > currentDurations)
        {
            currentNote = melodis[currentMelody].NextNote(numBuzzer);
            if (currentNote.note == NOTE_SILENCE)
                noTone(pin);
            else 
                tone(pin, currentNote.note);
            currentDurations = round(BUZZER_NOTE_DURATION*currentNote.durations);
            noteStartedMs = millis();
        }
    }

private:
    int pin;
    int numBuzzer;

    Note currentNote;
    uint64_t currentDurations;
    uint64_t noteStartedMs;

    int currentMelody;
    Melody* melodis; 
    int countMelody;
};
