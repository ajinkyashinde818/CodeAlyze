import sys
input = sys.stdin.readline

K, N = map(int, input().split())
A = [int(x) for x in input().split()]

A.append(K+A[0])

B = []
for i in range(1,N+1) :
    B.append(A[i] - A[i-1])

print(sum(B)-max(B))
