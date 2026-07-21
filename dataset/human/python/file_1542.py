import sys
import os

def is_same(a, b):
    for i in range(len(a)):
        if a[i] != b[i]:
            return False
    return True

N, M = list(map(lambda x: int(x), sys.stdin.readline().strip().split(" ")))

A = []
B = []

for _ in range(N):
    A.append(sys.stdin.readline().strip())

for _ in range(M):
    B.append(sys.stdin.readline().strip())

it = N - M + 1

for i in range(it):
    for j in range(it):
        a = list(map(lambda x: x[j:j+M], A[i:i+M]))
        if is_same(a, B):
            print("Yes")
            sys.exit(0)
print("No")
