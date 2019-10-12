''' 
Melody Avengers = Melody(2, 25);
    Avengers.setMelody(new Measure[1]{
        Measure(
        new int[6]{NOTE_D4, NOTE_SILENCE, NOTE_D4, NOTE_D4, NOTE_SILENCE, NOTE_D4},
        new double[6]{4, 2, 2, 4, 2, 2},
        6) 
    }, 1);
    Avengers.setMelody(new Measure[25]{
        Measure(
        new int[2]{NOTE_F2, NOTE_SILENCE},
        new double[2]{4, 12},
        2)
    }, 2);
'''
f = open('Melody2.txt', 'r')
name = f.readline().strip()
count_buzzer, count_measure = map(int, f.readline().split(' '))
dict = {}
dict1 = {}
for i in range(0, count_buzzer):
    dict[i] = []
    dict1[i] = []
for i in range(0, count_measure):
    f.readline()
    for j in range(0, count_buzzer):
        notes = map(str.strip, f.readline().split(','))
        notes = map(lambda st: f'NOTE_{st}', notes)
        _str = ', '.join(notes)
        dict[j].append(_str[:len(_str)])
        dict1[j].append(f.readline().strip())
    
_str = f'Melody {name} = Melody({count_buzzer}, {count_measure});\n'
strs = [] 
for i in range(0, count_buzzer):
    strs.append(f'{name}}.setMelody(new Measure[{count_measure}]{{\n')
    for j in range(0, count_measure):
        strs.append(f'Measure(')
        count = len(dict1[i][j].split())
        strs.append(f'new int[{count}]{{{dict[i][j]}}}, ')
        strs.append(f'new double[{count}]{{{dict1[i][j]}}}, ')
        strs.append(f'{count})')
        if j == count_measure - 1:
            strs.append('\n')
        else:
            strs.append(',\n')
    strs.append(f'}}, {i});\n') 

print(_str + ''.join(strs))