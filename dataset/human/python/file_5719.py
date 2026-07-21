from math import ceil
S=list(input())
num_x=S.count("x")
N=len(S)
num=N-num_x
cf,cr=0,0
F,R=[],[]

f,r=0,N-1
while len(F)<ceil(num/2):
  if S[f]=="x":
    cf+=1
  else:
    F.append((S[f],cf))
    cf=0
  f+=1
      
while len(R)<ceil(num/2):
  if S[r]=="x":
    cr+=1
  else:
    R.append((S[r],cr))
    cr=0
  r-=1
ans=0  
for i in range(ceil(num/2)):   
  if F[i][0]!=R[i][0]:
    print(-1)
    exit()
  else:
    ans+=abs(F[i][1]-R[i][1])
print(ans)
