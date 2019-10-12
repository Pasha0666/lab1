#pragma once

class Note{
    public:
    Note(){
    }
    Note(int _note, double _durations){
        note = _note;
        durations = _durations;
    }
    int note;
    double durations;
};

class Measure{
public:
    Measure(int _notes[], double _durations[], int _measureLength){
        notes = _notes;
        durations = _durations;
        measureLength = _measureLength;
        currentNote = 0;
        endMeasure = false;
    }
//кидаю false если такт закончен
    bool  LastNoteInMeasure(){
        return endMeasure;
    }
    void resetMeasure(){
      currentNote = 0;
    }
    Note getNote(){
        Note _note = Note(notes[currentNote], durations[currentNote]);
        currentNote = (currentNote + 1) % measureLength;
        endMeasure = currentNote == 0;
        return _note;
    }

    int* notes;
    double* durations;
    int measureLength;
private:
    bool endMeasure;
    int currentNote;
};

class Melody{
public:
  Melody(){
  }
  Melody(int _countBuzzer, int _measureLength){
      measureLength = _measureLength;
      countBuzzer = _countBuzzer;
      measures = new Measure* [countBuzzer];
      currentMeasure = new int[countBuzzer];
      for(int i = 0; i < countBuzzer ;i++)
          currentMeasure[i] = 0; 
  }
  void setMelodyForBuzzerNum(Measure _measures[], int _numBuzzer){
      measures[_numBuzzer] = _measures;
  }
  void resetMelody(){
      for(int i = 0; i < countBuzzer; i++){
          for(int j = 0; j < measureLength; j++)
              measures[i][j].resetMeasure();
          currentMeasure[i] = 0; 
      }
  }
  Note NextNote(int _numBuzzer){
    Note _note = measures[_numBuzzer][currentMeasure[_numBuzzer]].getNote();
    if (measures[_numBuzzer][currentMeasure[_numBuzzer]].LastNoteInMeasure()) 
        currentMeasure[_numBuzzer] = (currentMeasure[_numBuzzer] + 1) % measureLength;
    return _note;
  }
  
  Measure** measures;
  int measureLength;
private:
  int* currentMeasure;
  int countBuzzer;
};
