import sys
sr = lambda: sys.stdin.readline().rstrip()
ir = lambda: int(sr())
lr = lambda: list(map(int, sr().split()))
from collections import deque
def resolve():
    S = deque(sr())
    Q = ir()
    rev = 1
    for i in range(Q):
        T = list(sr().split())
        if int(T[0]) == 1:
            rev *= -1
        else:
            x, F, C = T
            if int(F) == 1:
                if rev == 1:
                    S.appendleft(C)
                else:
                    S.append(C)
            else:
                if rev == 1:
                    S.append(C)
                else:
                    S.appendleft(C)
    if rev == -1:
        S.reverse()
    print(*S, sep='')
resolve()
