from sys import stdin
N,K = [int(x) for x in stdin.readline().rstrip().split()]
A = [int(x) for x in stdin.readline().rstrip().split()]
dist = []
dist.append(N - A[-1] + A[0])
ans = 10**18
for i in range(0,K-1):
    dist.append(A[i+1]-A[i])

s = sum(dist)
for i in dist:
    ans = min(ans,s-i)
print(ans)
