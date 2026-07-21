import sys
input = sys.stdin.readline
n,k,s=map(int,input().split())
if k==0:
    if s<10**9:
        a=s+1
    else:
        a=s-1
    ans=[]
    for i in range(n):
        ans.append(a)
    print(*ans)
    exit()
ans=[]
for i in range(n-k):
    if s<10**9:
        a=s+1
    else:
        a=s-1
    ans.append(a)
for j in range(k):
    ans.append(s)
print(*ans)
