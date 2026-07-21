D,G=map(int,input().split())
PC=[list(map(int,input().split())) for i in range(D)]
ans=10**18
import math
for i in range(2**D):
  _i=i
  j=0
  s=[]
  _ans=0
  g=0
  while i>0:
    if i%2==1:
      _ans+=PC[j][0]
      g+=(PC[j][0]*100*(j+1)+PC[j][1])
      s.append(j)
    j+=1
    i=i//2
  if g>=G:
    ans=min(ans,_ans)
  else:
    j=D-1
    while j in s:
      j-=1
    if j>-1 and G-g<=(PC[j][0]-1)*100*(j+1):
      _ans+=math.ceil((G-g)/100/(j+1))
      ans=min(ans,_ans)
print(ans)
