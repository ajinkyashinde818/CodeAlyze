import sys
from itertools import combinations
import math


def I(): return int(sys.stdin.readline().rstrip())


def LI(): return list(map(int, sys.stdin.readline().rstrip().split()))


def S(): return sys.stdin.readline().rstrip()


def LS(): return list(sys.stdin.readline().rstrip().split())


S = S()

while 1:
    for flag in ("erase", "eraser", "dream", "dreamer"):
        if S.endswith(flag):
            S = S[:-len(flag)]
            break
    else:
        print('NO')
        break
    if not S:
        print('YES')
        break
