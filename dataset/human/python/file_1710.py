import sys

import numpy as np

input = sys.stdin.readline


def main():
    N, M = map(int, input().split())
    A = np.full((N, N), "", dtype=str)
    for i in range(N):
        A[i] = list(input().rstrip())
    B = np.full((M, M), "", dtype=str)
    for i in range(M):
        B[i] = list(input().rstrip())

    ans = "No"
    L = N - (M - 1)
    for i in range(L):
        for j in range(L):
            if np.all(A[i:i + M, j:j + M] == B):
                ans = "Yes"
    print(ans)


if __name__ == "__main__":
    main()
