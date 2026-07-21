import sys
input=sys.stdin.readline
n=int(input())
a_list=list(map(int,input().split()))
S=sum(a_list)
x=0
ans=10**20
for i in range(n-1):
    x+=a_list[i]
    y=S-x
    temp=abs(x-y)
    ans=min(ans,temp)
print(ans)
