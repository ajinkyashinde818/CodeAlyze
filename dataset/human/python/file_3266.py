from collections import defaultdict
N=int(input())
soinsu=defaultdict(int)
x=2
while x<=10**6:
  while N%x==0:
    soinsu[x]+=1
    N//=x
  x+=1
  
if N>1:
  soinsu[N]+=1
  
ans=0
for key in soinsu.keys():
  x=1
  while soinsu[key]>=x:
    ans+=1
    soinsu[key]-=x
    x+=1
    
print(ans)
