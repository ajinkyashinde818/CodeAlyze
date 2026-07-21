import sys
input = sys.stdin.readline
from fractions import gcd


def read():
    N, M = map(int, input().strip().split())
    A = []
    B = []
    for i in range(N):
        a = input().strip()
        A.append(a)
    for i in range(M):
        b = input().strip()
        B.append(b)
    return N, M, A, B


def solve(N, M, A, B):
    R = N - M
    C = len(A[0]) - len(B[0])
    if R < 0 or C < 0:
        return "No"
    L = len(B[0])
    for i in range(R+1):
        for j in range(C+1):
            is_match = True
            for k in range(M):
                if A[i+k][j:j+L] != B[k]:
                    is_match = False
                    break
            if is_match:
                return "Yes"
    return "No"


if __name__ == '__main__':
    inputs = read()
    print(solve(*inputs))
