n,m=map(int,input().split())
a=[input() for _ in range(n)]
b=[input() for _ in range(m)]

for i in range (n-m+1):#行
  for j in range(n-m+1):#列
    g=1
    for k in range(m):#m
      
      if a[i+k][j:j+m]!=b[k]:
        g*=0
        break
    if g==1:
      print("Yes")
      import sys
      sys.exit()
else:
  print("No")
