import sys
input = sys.stdin.readline

K, N = map(int, input().split())
A = list(map(int, input().split()))

dist = []
A = [0] + A + [K+A[0]]

max_d = 0
for i in range(1, N+2):
    d = A[i]-A[i-1]
    dist.append(d)

    if d > max_d:
        max_d = d

print(K-max_d)
