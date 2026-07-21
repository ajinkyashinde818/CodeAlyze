import numpy as np
import copy
from collections import deque

S = str(input())
Q = int(input())

Que = [0]* Q
for i in range(Q):
    Que[i] = list(map(str, input().split()))

check = 1
L = deque()
R = deque()
for i in range(Q):
    T = Que[i][0]
    if int(T) == 1:
        check *= -1
    else:
        F = Que[i][1]
        if (int(F) == 1 and check == 1) or (int(F) == 2 and check == -1):
#            answer = ''.join([Que[i][2], answer])
            L.appendleft(Que[i][2])
        else:
#            answer = ''.join([answer, Que[i][2]])
            R.append(Que[i][2])
answer = ''.join(L) + S + ''.join(R)
if check == -1:
    answer = ''.join(list(reversed(answer)))
print(answer)
