import sys
from collections import deque

INPUT = lambda: sys.stdin.readline().rstrip()
INT = lambda: int(INPUT())


def main():
    S = deque(INPUT())
    Q = INT()

    flag_order = True
    D_MAP = lambda: map(str, query.split())
    for i in range(Q):
        query = INPUT()
        if len(query.split()) == 1:
            T = 1
        else:
            T = 2
            _, F, C = D_MAP()
            F = int(F)

        if T == 1:
            if flag_order: flag_order = False
            else: flag_order = True
        if T == 2:
            if flag_order:
                if F == 1: S.appendleft(C)
                else: S.append(C)
            else:
                if F == 1: S.append(C)
                else: S.appendleft(C)

    print(''.join(S) if flag_order else ''.join(reversed(S)))


if __name__ == '__main__':
    main()
