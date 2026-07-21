import sys
input = sys.stdin.readline

K,N = map(int, input().split())
A = list(map(int, input().split()))
d = [0]*N
for i in range(N):
    t = i+1
    if i+1 == N:
        t = 0
    d[i] = min(abs(A[i]-A[t]), abs(K-A[i])+A[t])
print(sum(d)-max(d))
