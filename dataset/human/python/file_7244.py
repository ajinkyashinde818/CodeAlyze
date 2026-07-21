import numpy as np
import sys

input = sys.stdin.readline

S = input()
Q = int(input())

left = []
right = []
rev = False

for i in range(Q):
    l = input().split()
    if l[0] == '1':
        rev = not rev
    else:
        if (l[1] == '1' and not rev) or (l[1] == '2' and rev):
            left.append(l[2])
        else:
            right.append(l[2])

S = ''.join(left[::-1]) + S + ''.join(right)

if rev:
    print(S[::-1].replace('\n',''))
else:
    print(S.replace('\n',''))
