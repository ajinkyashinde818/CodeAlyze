D,G=map(int,input().split())
import math
ans=10**9
prob=[]
for i in range(D):
  p,c=map(int,input().split())
  prob.append((p,c))
for i in range(2**D):
  i=format(i-1,'b').rjust(D,'0')
  alll=[]
  notall=[]
  for j in range(D):
    if i[j]=='1':
      alll.append(j)
    else:
      notall.append(j)
  if notall!=[]:
    maxnotall=notall[-1]  
  point=0
  tans=0
  for i in alll:
    point+=100*(i+1)*prob[i][0]+prob[i][1]
    tans+=prob[i][0]
  if point>=G:
    ans=min(tans,ans)
  if point<G:
    if 100*(maxnotall+1)*(prob[maxnotall][0]-1)>=G-point:
      tans+=math.ceil((G-point)/(100*(maxnotall+1)))
      ans=min(tans,ans)
    else:
      ans=ans

if ans==10**9:
  ans=0
  for i in range(D):
    ans+=prob[i][0]
print(ans)
