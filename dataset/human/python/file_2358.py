from itertools import groupby, accumulate, product, permutations, combinations
def solve():
  ans = 2000
  D, G = map(int, input().split())
  P = [0]*D
  C = [0]*D
  for i in range(D):
    P[i],C[i] = map(int, input().split())
  for p in product([0,1],repeat=D):
    if sum(p)<D:
      for i in range(D-1,-1,-1):
        if p[i]==0:
          maxi = i
          break
    cnt = 0
    score = 0
    for i in range(D):
      if p[i]==1:
        score += (i+1)*100*P[i]+C[i]
        cnt += P[i]  
    if -(-(G-score)//(100*(maxi+1)))>=P[maxi]:
      continue
    if G>score:
      cnt += -(-(G-score)//(100*(maxi+1)))
    ans = min(ans,cnt)
  return ans
print(solve())
