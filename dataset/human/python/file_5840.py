import sys
input=sys.stdin.readline
n=int(input())
a_list=list(map(int,input().split()))
b_list=list(map(int,input().split()))
c_list=list(map(int,input().split()))
pre=100
ans=0
for x in a_list:
    if x==pre+1:
        ans+=c_list[x-2]
    ans+=b_list[x-1]
    pre=x
print(ans)
