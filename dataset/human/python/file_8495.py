import sys
input=sys.stdin.readline
k,n=map(int,input().split())
a_list=list(map(int,input().split()))
ans=10**9
for i in range(n):
    if i==0:
        t=a_list[n-1]-a_list[0]
        ans=t
    else:
        t=k-a_list[i]+a_list[i-1]
        ans=min(ans,t)
print(ans)
