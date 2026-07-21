from collections import deque

S = deque([x for x in input()])
Q = int(input())
switch = 0
for _ in range(Q):
    inp = input()
    if len(inp) == 1:
        T = int(inp)
        if switch:
            switch = 0
        else:
            switch = 1
    else:
        T, F = map(int, inp.split()[:2])
        C = inp.split()[-1]
        if F == 1:
            if switch:
                S.append(C)
            else:
                S.appendleft(C)
        else:
            if switch:
                S.appendleft(C)
            else:
                S.append(C)
if switch:
    print("".join(list(S)[::-1]))
else:
    print("".join(S))
