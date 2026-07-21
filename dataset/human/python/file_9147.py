import math
import numpy as np

S = str(input())

divider = ['maerd', 'remaerd', 'esare', 'resare']

S_reverse = S[::-1]
can = 1
i = 0

while i < len(S):
    can2 = 0
    for j in range(4):
        d = divider[j]
        if S_reverse[i:i+len(d)] == d:
            can2 = 1
            i += len(d)
            break
    if can2 == 0:
        can = 0
        break

if can == 1:
    print('YES')
else:
    print('NO')
