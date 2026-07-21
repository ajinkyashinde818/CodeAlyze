import math

n,g=map(int,input().split())
arr=[list(map(int,input().split())) for _ in range(n)]
comp=[(100*(i+1)*arr[i][0]+arr[i][1]) for i in range(n)]
ans=10**10
for i in range(2**n):
  flag=format(i,'b')
  if len(flag)<n:
    flag='0'*(n-len(flag))+flag
  tsum=0
  tans=0
  for i in range(n):
    if flag[i]=='1':
      tsum+=comp[i]
      tans+=arr[i][0]
  if tsum>=g:
    ans=min(ans,tans)
  else:
    pos=flag[::-1].index('0')
    tq=math.ceil((g-tsum)/(100*(n-pos)))
    if tq<=arr[n-pos-1][0]:
      ans=min(ans,tans+tq)
print(ans)
