import itertools
import math

d,g=list(map(int,input().split()))
PC=[list(map(int,input().split())) for _ in range(d)]
ans=[]

for i in range(d+1):
  for j in itertools.combinations(range(d),i):
    score,pro1=0,0
    for k in j:
      score += (PC[k][1] + (k+1) * 100 * PC[k][0])
      pro1 += PC[k][0]
    for k in range(d):
      pro2 = pro1
      if score >= g:
        ans.append(pro2)
      elif k in j:
        continue
      p=math.ceil((g-score) / ((k+1) * 100))
      if 0 < p < PC[k][0]:
        pro2 += p
        ans.append(pro2)
        
print(min(ans))
