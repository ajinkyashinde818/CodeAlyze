import os
import sys

if os.getenv("LOCAL"):
    sys.stdin = open("_in.txt", "r")

sys.setrecursionlimit(2147483647)
INF = float("inf")
IINF = 10 ** 18
MOD = 10 ** 9 + 7

N = int(sys.stdin.readline())
A = list(map(int, sys.stdin.readline().split()))


def solve(A):
    if N == 1:
        return True

    S = sum(A)
    if S % ((N + 1) * N // 2) != 0:
        return False
    # 箱を選ぶ回数
    K = S // ((N + 1) * N // 2)

    cnt = 0
    for i in range(N):
        j = (i + 1) % N
        d = A[j] - A[i]
        if (K - d) % N != 0:
            return False
        if (K - d) // N < 0:
            return False
        cnt += (K - d) // N
    return cnt == K


if solve(A):
    print('YES')
else:
    print('NO')
