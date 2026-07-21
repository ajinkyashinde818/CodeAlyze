import sys
def input(): return sys.stdin.readline().strip()

K, N = map(int, input().split())
A = list(map(int, input().split()))

dist = 0
start = -1
for i in range(N - 1):
    a = A[i + 1]
    pre = A[i]
    if dist < a - pre:
        dist = a - pre
        start = i

if dist < A[0] + (K - A[N - 1]):
    dist = A[0] + (K - A[N - 1])
    start = N - 1

print(K - dist)
