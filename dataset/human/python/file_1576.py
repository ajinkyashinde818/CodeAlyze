n,m = map(int,input().split())
aa = [input() for _ in range(n)]
bb = [input() for _ in range(m)]

def template_matching():
  for y in range(n-m+1):   
    for x in range(n-m+1):
      flag = True
      for yi in range(m):
        if aa[y+yi].find(bb[yi],x)-x != 0:          
          flag = False
      if flag :
        return True
  return False

if template_matching():
  print('Yes')
else:  
  print('No')
