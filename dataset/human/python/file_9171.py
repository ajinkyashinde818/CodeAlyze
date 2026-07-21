from sys import stdin
import sys

s = stdin.readline().rstrip()

A = 'dream'
B = 'dreamer'
C = 'erase'
D = 'eraser'

s = s[::-1]
A = A[::-1]
B = B[::-1]
C = C[::-1]
D = D[::-1]

while True:
    if len(s) >= 5 and s[:5] == A:
        s = s[5:]
    elif len(s) >= 7 and s[:7] == B:
        s = s[7:]
    elif len(s) >= 5 and s[:5] == C:
        s = s[5:]
    elif len(s) >= 6 and s[:6] == D:
        s = s[6:]
    else:
        print("NO")
        sys.exit()

    if s == '':
        print ("YES")
        sys.exit()
