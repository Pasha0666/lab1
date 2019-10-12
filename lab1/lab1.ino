#include <Arduino.h>

#include "button.h"
#include "buzzer.h"

#define PIN_BUZZER_1 6
#define PIN_BUZZER_2 7
#define PIN_BUTTON 5

Button buttonOff(PIN_BUTTON);
int countBuzzer = 2;
Buzzer buzzers[2] = {
    Buzzer(PIN_BUZZER_1, 0, 2),
    Buzzer(PIN_BUZZER_2, 1, 2)
};

void setup() {
    Melody Avengers = Melody(2, 25);
    Avengers.setMelodyForBuzzerNum(new Measure[25]{
        Measure(new int[6]{NOTE_D4, NOTE_SILENCE, NOTE_D4, NOTE_D4, NOTE_SILENCE, NOTE_D4}, new double[6]{4, 2, 2, 4, 2, 2}, 6),
        Measure(new int[6]{NOTE_DS4, NOTE_SILENCE, NOTE_DS4, NOTE_E4, NOTE_SILENCE, NOTE_E4}, new double[6]{4, 2, 2, 4, 2, 2}, 6),
        Measure(new int[6]{NOTE_F4, NOTE_SILENCE, NOTE_F4, NOTE_E4, NOTE_SILENCE, NOTE_E4}, new double[6]{4, 2, 2, 4, 2, 2}, 6),
        Measure(new int[5]{NOTE_DS4, NOTE_SILENCE, NOTE_DS4, NOTE_AS3, NOTE_C4}, new double[5]{4, 2, 2, 4, 4}, 5),
        Measure(new int[6]{NOTE_D4, NOTE_SILENCE, NOTE_D4, NOTE_D4, NOTE_SILENCE, NOTE_D4}, new double[6]{4, 2, 2, 4, 2, 2}, 6),
        Measure(new int[6]{NOTE_DS4, NOTE_SILENCE, NOTE_DS4, NOTE_E4, NOTE_SILENCE, NOTE_E4}, new double[6]{4, 2, 2, 4, 2, 2}, 6),
        Measure(new int[6]{NOTE_F4, NOTE_SILENCE, NOTE_F4, NOTE_E4, NOTE_SILENCE, NOTE_E4}, new double[6]{4, 2, 2, 4, 2, 2}, 6),
        Measure(new int[5]{NOTE_DS4, NOTE_SILENCE, NOTE_DS4, NOTE_AS3, NOTE_C4}, new double[5]{4, 2, 2, 4, 4}, 5),
        Measure(new int[1]{NOTE_G3}, new double[1]{16}, 1),
        Measure(new int[4]{NOTE_D4, NOTE_C4, NOTE_AS3, NOTE_C4}, new double[4]{4, 4, 4, 4}, 4),
        Measure(new int[2]{NOTE_D4, NOTE_G3}, new double[2]{4, 12}, 2),
        Measure(new int[4]{NOTE_D4, NOTE_C4, NOTE_AS3, NOTE_A3}, new double[4]{4, 4, 4, 4}, 4),
        Measure(new int[1]{NOTE_G3}, new double[1]{16}, 1),
        Measure(new int[4]{NOTE_D4, NOTE_C4, NOTE_AS3, NOTE_C4}, new double[4]{4, 4, 4, 4}, 4),
        Measure(new int[2]{NOTE_D4, NOTE_G3}, new double[2]{4, 12}, 2),
        Measure(new int[4]{NOTE_D4, NOTE_C4, NOTE_AS3, NOTE_A3}, new double[4]{4, 4, 4, 4}, 4),
        Measure(new int[1]{NOTE_G3}, new double[1]{16}, 1),
        Measure(new int[4]{NOTE_D5, NOTE_C5, NOTE_AS4, NOTE_C5}, new double[4]{4, 4, 4, 4}, 4),
        Measure(new int[2]{NOTE_D5, NOTE_G4}, new double[2]{4, 12}, 2),
        Measure(new int[4]{NOTE_D5, NOTE_C5, NOTE_AS4, NOTE_A4}, new double[4]{4, 4, 4, 4}, 4),
        Measure(new int[1]{NOTE_G4}, new double[1]{16}, 1),
        Measure(new int[4]{NOTE_D5, NOTE_C5, NOTE_AS4, NOTE_C5}, new double[4]{4, 4, 4, 4}, 4),
        Measure(new int[2]{NOTE_D5, NOTE_G4}, new double[2]{4, 12}, 2),
        Measure(new int[4]{NOTE_D5, NOTE_C5, NOTE_AS4, NOTE_A4}, new double[4]{4, 4, 4, 4}, 4),
        Measure(new int[1]{NOTE_A4}, new double[1]{16}, 1)
    }, 0);
    Avengers.setMelodyForBuzzerNum(new Measure[25]{
        Measure(new int[2]{NOTE_F2, NOTE_SILENCE}, new double[2]{4, 12}, 2),
        Measure(new int[1]{NOTE_SILENCE}, new double[1]{16}, 1),
        Measure(new int[1]{NOTE_SILENCE}, new double[1]{16}, 1),
        Measure(new int[1]{NOTE_SILENCE}, new double[1]{16}, 1),
        Measure(new int[2]{NOTE_F2, NOTE_SILENCE}, new double[2]{4, 12}, 2),
        Measure(new int[1]{NOTE_SILENCE}, new double[1]{16}, 1),
        Measure(new int[1]{NOTE_SILENCE}, new double[1]{16}, 1),
        Measure(new int[4]{NOTE_F2, NOTE_SILENCE, NOTE_D2, NOTE_DS2}, new double[4]{4, 4, 4, 4}, 4),
        Measure(new int[1]{NOTE_D2}, new double[1]{16}, 1),
        Measure(new int[2]{NOTE_DS2, NOTE_E2}, new double[2]{8, 8}, 2),
        Measure(new int[2]{NOTE_F2, NOTE_E2}, new double[2]{8, 8}, 2),
        Measure(new int[3]{NOTE_DS2, NOTE_AS1, NOTE_C2}, new double[3]{8, 4, 4}, 3),
        Measure(new int[1]{NOTE_D2}, new double[1]{16}, 1),
        Measure(new int[2]{NOTE_DS2, NOTE_E2}, new double[2]{8, 8}, 2),
        Measure(new int[2]{NOTE_F2, NOTE_E2}, new double[2]{8, 8}, 2),
        Measure(new int[3]{NOTE_DS2, NOTE_AS1, NOTE_C2}, new double[3]{8, 4, 4}, 3),
        Measure(new int[1]{NOTE_D2}, new double[1]{16}, 1),
        Measure(new int[2]{NOTE_DS2, NOTE_E2}, new double[2]{8, 8}, 2),
        Measure(new int[2]{NOTE_F2, NOTE_E2}, new double[2]{8, 8}, 2),
        Measure(new int[3]{NOTE_DS3, NOTE_AS2, NOTE_C3}, new double[3]{8, 4, 4}, 3),
        Measure(new int[1]{NOTE_D2}, new double[1]{16}, 1),
        Measure(new int[2]{NOTE_DS2, NOTE_E2}, new double[2]{8, 8}, 2),
        Measure(new int[2]{NOTE_F2, NOTE_E2}, new double[2]{8, 8}, 2),
        Measure(new int[3]{NOTE_DS3, NOTE_AS2, NOTE_C3}, new double[3]{8, 4, 4}, 3),
        Measure(new int[1]{NOTE_A2}, new double[1]{16}, 1)
    }, 1);
    buzzers[0].setMelody(Avengers, 0);
    buzzers[1].setMelody(Avengers, 0);

    Melody Melody2 = Melody(2, 9);
    Melody2.setMelodyForBuzzerNum(new Measure[9]{
        Measure(new int[1]{NOTE_D4}, new double[1]{4}, 1),
        Measure(new int[5]{NOTE_G4, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_FS4}, new double[5]{4, 2, 2, 2 ,2}, 5),
        Measure(new int[3]{NOTE_E4, NOTE_C4, NOTE_E4}, new double[3]{4, 4, 4}, 3),
        Measure(new int[5]{NOTE_A4, NOTE_A4, NOTE_B4, NOTE_A4, NOTE_G4}, new double[5]{4, 2, 2, 2, 2}, 5),
        Measure(new int[3]{NOTE_FS4, NOTE_D4, NOTE_D4}, new double[3]{4, 4, 4}, 3),
        Measure(new int[5]{NOTE_B4, NOTE_B4, NOTE_C5, NOTE_B4, NOTE_A4}, new double[5]{4, 2, 2, 2 ,2}, 5),
        Measure(new int[4]{NOTE_G4, NOTE_E4, NOTE_D4, NOTE_D4}, new double[4]{4, 4, 2, 2}, 4),
        Measure(new int[3]{NOTE_E4, NOTE_A4, NOTE_FS4}, new double[3]{4, 4, 4}, 3),
        Measure(new int[1]{NOTE_G4}, new double[1]{8}, 1)
    }, 0);
    Melody2.setMelodyForBuzzerNum(new Measure[9]{
        Measure(new int[1]{NOTE_SILENCE}, new double[1]{4}, 1),
        Measure(new int[1]{NOTE_G2}, new double[1]{12}, 1),
        Measure(new int[1]{NOTE_C2}, new double[1]{12}, 1),
        Measure(new int[1]{NOTE_A3}, new double[1]{12}, 1),
        Measure(new int[1]{NOTE_D3}, new double[1]{12}, 1),
        Measure(new int[1]{NOTE_B3}, new double[1]{12}, 1),
        Measure(new int[1]{NOTE_E2}, new double[1]{12}, 1),
        Measure(new int[2]{NOTE_C2, NOTE_D2}, new double[2]{8, 4}, 2),
        Measure(new int[1]{NOTE_G2}, new double[1]{8}, 1)
    }, 1);
    buzzers[0].setMelody(Melody2, 1);
    buzzers[1].setMelody(Melody2, 1);
}

void loop() {
    for (int i = 0; i < countBuzzer; i++)
        buzzers[i].playSound();
    if (buttonOff.wasPressed())
      for (int i = 0; i < countBuzzer; i++)
      {
          buzzers[i].setNextMelody();
      }
}
