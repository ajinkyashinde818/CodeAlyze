import sys
input=sys.stdin.readline
N=int(input())
num = list(map(int,input().split()))
c=0
ans=0
for i in range(N):
  if num[i]<0:
    c+=1 
ans = list(map(lambda x: abs(x),num))
if c%2==0:
  print(sum(ans))
else:
  print(sum(ans) - min(ans,key=lambda x: abs(x))*2)
