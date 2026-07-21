import sys
from collections import deque


inint = lambda: int(sys.stdin.readline())
inintm = lambda: map(int, sys.stdin.readline().split())
inintl = lambda: list(inintm())
instrm = lambda: map(str, sys.stdin.readline().split())
instrl = lambda: list(instrm())

s = input()
q = inint()

S = deque()
f = [0,1]

for i in range(len(s)):
    S.append(s[i])

for i in range(q):
    Q = instrl()
    if Q[0] == "1":
        f = f[::-1]
    else:
        if f[0] == 0:
            if Q[1] == "1":
                S.appendleft(Q[2])
            else:
                S.append(Q[2])
        else:
            if Q[1] == "1":
                S.append(Q[2])
            else:
                S.appendleft(Q[2])

if f[0] == 1:
    S.reverse()

print("".join(S))
