from collections import deque
from sys import stdin

def main():
    S = deque([s for s in input()])
    Q = int(input())
    order = True
    for i in range(Q):
        query = stdin.readline()
        t = int(query[0])
        if t == 1:
            order = not order
        else:
            f = int(query[2])
            c = query[4]
            if not order:
                f = 3  - f # 2, 1 -> 1, 2
            left = True
            if f == 1:
                S.appendleft(c)
            else:
                S.append(c)
    if not order:
        S.reverse()
    print(''.join(S))

if __name__ == '__main__':
    main()
