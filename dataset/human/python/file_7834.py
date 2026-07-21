import sys,math,collections,itertools
input = sys.stdin.readline

N,K,S=list(map(int,input().split()))
if S == 10**9:
    ans = [10**9-1]*N
else:
    ans = [10**9]*N
for i in range(K):
    ans[i]=S
print(*ans)
