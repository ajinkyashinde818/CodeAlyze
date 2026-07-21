from sys import stdin
import sys

S = stdin.readline().rstrip()
T = ''

data = ['dream', 'erase', 'dreamer', 'eraser']

if len(S) < len('dream'):
    print('NO')
    sys.exit()

pos = 0

OTHER=0
DREAM=1
ERASE=2
last_word = OTHER

while pos < len(S):
    if S[pos:pos+len(data[0])] == data[0]:
        pos = pos + len(data[0])
        last_word = DREAM
    elif S[pos:pos+len(data[1])] == data[1]:
        pos = pos + len(data[1])
        last_word = ERASE
    elif S[pos:pos+len(data[2])] == data[2]:
        pos = pos + len(data[2])
        last_word = OTHER
    elif S[pos:pos+len(data[3])] == data[3]:
        pos = pos + len(data[3])
        last_word = OTHER
    elif last_word == DREAM and S[pos:pos+len('er')] == 'er':
        pos = pos + len('er')
        last_word = OTHER
    elif last_word == ERASE and S[pos:pos+len('r')] == 'r':
        pos = pos + len('r')
        last_word = OTHER
    else:
        print('NO')
        sys.exit()


print('YES')
