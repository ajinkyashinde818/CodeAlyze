from collections import defaultdict
def factorize(M):
  res=defaultdict(int)
  for i in range(2,int(M**0.5)+1):
    if M==1:
      break
    while M%i==0:
      M//=i
      res[i]+=1  
  if M!=1:
    res[M]=1
  return res

N=int(input())
fact=factorize(N)
#print(fact)

def times(n):
  s=0
  for i in range(1,10**9):
    s+=i
    if n<s:
      return i-1
    
answer=0
for v in fact.values():  
  #print(v,times(v))
  answer+=times(v)
  
print(answer)
