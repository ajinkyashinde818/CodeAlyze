from collections import defaultdict

D,G=map(int,input().split())

bonus=[]

for i in range(D):
  a,b=map(int,input().split())
  bonus.append([a,b])

def solve(bit):
  ans=0
  turn=0
  for j in range(D):
    if (bit >> j ) % 2:
      ans+=(bonus[j][0] * (j+1) * 100 + bonus[j][1])
      turn+=bonus[j][0]
  if ans >= G:
    return turn
  for k in range(D-1,-1,-1):
    if (bit >> k ) % 2 == 0:
      for l in range(bonus[k][0]-1):
        ans += (k+1)*100
        turn += 1
        if ans >= G:
          return turn
  return -1
        

bits = (1 << D)

res=10**10
for i in range(bits):
  c=solve(i)
  if c > 0:
    res=min(res,c)
  
print(res)
