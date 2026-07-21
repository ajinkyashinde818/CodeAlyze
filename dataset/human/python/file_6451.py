import sys
stdin = sys.stdin
import copy

ns = lambda: stdin.readline().rstrip()
ni = lambda: int(ns())
na = lambda: list(map(int, stdin.readline().split()))

n = ni()
if n % 2 != 0:
    print(0)
else:
    n2 = copy.copy(n)
    n5 = copy.copy(n)
    c2, c5 = 0, 0
    while n2 > 1:
        n2 //= 2
        c2 += n2
    while n5 > 1:
        n5 //= 5
        c5 += n5//2
    print(min(c2, c5))
