import sys
input = sys.stdin.readline

N = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))
C = list(map(int, input().split()))
A += [0]

s = 0
for i in range(N):
    if A[i + 1] - A[i] == 1:
        s += C[A[i] - 1]
    else:
        continue

print(s + sum(B))
