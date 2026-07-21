D,G=[ int(it) for it in input().split() ]
li = [ [ int(it) for it in input().split() ] for i in range(D) ]

import itertools as ite
cmin = 100000000000000000
for cli in ite.product( *([[0,1]]*D) ):
  
  s = 0
  c = 0
  for i in range(D):
    if cli[i]==1:
      s +=  li[i][1] + (i+1)*100*li[i][0]
      c +=  li[i][0]
  
  ds = G-s
  
  for i in range(D-1,-1,-1):
    if (ds<=0):
      break
    if cli[i]==0:
      toku = (ds-1)//((i+1)*100)+1
      toku = min(toku,li[i][0])
      c += toku
      ds -= toku*(i+1)*100
    if (ds<=0):
      break
  if (ds<=0):
    cmin = min(cmin,c)
  else:
    pass
print (cmin)
