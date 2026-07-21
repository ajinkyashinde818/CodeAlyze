import math  # noqa
import bisect  # noqa
import queue  # noqa


if __name__ == '__main__':
    N, M = map(int, input().split())
    A = [[a for a in input()] for _ in range(N)]
    B = [[b for b in input()] for _ in range(M)]

    ans = False
    for i in range(0, N - M + 1):
        for j in range(0, N - M + 1):
            res = True
            for k in range(0, M):
                for l in range(0, M):
                    if A[i + k][j + l] != B[k][l]:
                        res = False
            if res:
                ans = True
                break

    if ans:
        print("Yes")
    else:
        print("No")
