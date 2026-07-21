import os
import sys

import numpy as np

if os.getenv("LOCAL"):
    sys.stdin = open("_in.txt", "r")

sys.setrecursionlimit(2147483647)
INF = float("inf")
IINF = 10 ** 18
MOD = 10 ** 9 + 7

N = int(sys.stdin.readline())
S = sys.stdin.readline().rstrip()


def factorial(n):
    ret = 1
    for a in range(2, n + 1):
        ret = ret * a % MOD
    return ret


def solve(S):
    S = np.array(list(S)) == 'B'
    # 右にするか左にするか
    LR = np.zeros_like(S, dtype=str)
    LR[::2][S[::2] == 0] = 'R'
    LR[::2][S[::2] == 1] = 'L'
    LR[1::2][S[1::2] == 0] = 'L'
    LR[1::2][S[1::2] == 1] = 'R'
    if (LR == 'R').sum() != len(LR) // 2:
        return 0
    l_cnt = (LR == 'L').cumsum()
    ans = 1
    r = 0
    for i, lr in enumerate(LR):
        if lr == 'R':
            l = l_cnt[i] - r
            if l <= 0:
                return 0
            ans = ans * l % MOD
            r += 1
    return ans * factorial(len(LR) // 2) % MOD


ans = solve(S)
print(ans)
