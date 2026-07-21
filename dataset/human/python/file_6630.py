from collections import deque
from sys import stdin


def main():
    input = lambda: stdin.readline()[:-1]
    S = input()
    Q = int(input())

    s = deque(S)
    left, right = s.appendleft, s.append
    rev = 0
    for _ in [0] * Q:
        T = input().split()
        if T[0] == '1':
            left, right = right, left
            rev += 1
        else:
            f, c = T[1], T[2]
            if f == '1':
                left(c)
            else:
                right(c)

    if rev % 2:
        s.reverse()
    print(''.join(s))


main()
