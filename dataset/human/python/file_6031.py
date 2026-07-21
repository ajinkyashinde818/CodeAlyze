import sys
input=sys.stdin.readline

n=int(input())
a=[]
for i in range(3):
    aa=list(map(int,input().split()))
    a.append(aa)
ans=0
num=-1
num2=-1
for j in a[0]:
    ans+=a[1][j-1]
    num2=j
    if num2-num==1:
        ans+=a[2][j-2]
    num=j
print(ans)
