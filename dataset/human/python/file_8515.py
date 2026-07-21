import sys
input = sys.stdin.readline

K, N = map(int, input().split())
A = list(map(int, input().split()))
d = []

for i in range(N-1):
    d.append(A[i+1]-A[i])

d.append(K+A[0]-A[-1])

print(K-max(d))
