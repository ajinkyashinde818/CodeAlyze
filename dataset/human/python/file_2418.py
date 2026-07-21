import math 
D, G = map(int, input().split())
K = [list(map(int, input().split())) for _ in range(D)]
G //= 100
def settify(i):
  s = []
  t = []
  for j in range(D):
    if i % 2 == 0:
      t.append(j)
    else:
      s.append(j)
    i = i>>1
    
  return s,t

ans = 10**20  
for i in range(2**D):
  s, t = settify(i)
  pt = sum([K[j][0]*(j+1)+K[j][1]//100 for j in s])
  tmp = sum([K[j][0] for j in s])
  #print(pt, G)
  #print(t)
  while pt < G and t:
    #print(min(K[t[-1]][0]-1,math.ceil((G-pt)/(t[-1]+1))),t[-1])
    tmp += min(K[t[-1]][0]-1,math.ceil((G-pt)/(t[-1]+1)))
    pt += min(K[t[-1]][0]-1,math.ceil((G-pt)/(t[-1]+1)))*(t[-1]+1)
    t.pop()
  #print(tmp,s,pt) 
  if pt < G:
    continue
  ans = min(ans, tmp)
    
print(ans)
