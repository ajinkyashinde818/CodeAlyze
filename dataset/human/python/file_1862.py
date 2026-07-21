import re
n,m = map(int, input().split())
a = [input().strip() for i in range(n)]
b = [input().strip() for i in range(m)]

mc = n-m+1
ans = False
for ai in range(0, mc):
  if(ans):
    break
  ind = [x.start() for x in re.finditer(b[0], a[ai])]
  if(m==1)and(len(ind)>0):
    ans=True
    break  
  for i in ind:
    if(ans):
      break
    for bi in range(1, m):
      if(a[ai+bi][i:i+m] != b[bi]):
        break
      if(bi==m-1):
        ans = True
        break
if(ans):
  print('Yes')
else:
  print('No')
