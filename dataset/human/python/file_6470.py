import sys; readline = sys.stdin.readline
from collections import deque


N = int(readline())


if N % 2 == 1:
    print(0)
    exit(0)

def count(d, n):
    c = 0
    a = n
    while True:
        a = a // d
        if a == 0:
            break
        c += a
    return c

print(min(count(2,N), count(5, N // 2)))
