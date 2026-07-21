import sys
input = sys.stdin.readline

N,K = map(int,input().rstrip().split())
A = [int(x)-1 for x in input().rstrip().split()]

now = 0
d = {}
if N < K:
    for i in range(0,N):
        if now in d:
            K -= d[now]
            K %= i-d[now]
            for j in range(K):
                now = A[now]
            break
        else:
            d[now] = i

        now = A[now]
else:
    for j in range(K):
        now = A[now]
        
print(now+1)
