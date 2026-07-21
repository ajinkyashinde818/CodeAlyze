import sys
n,m=map(int,input().split())
INF=10**15
li1=set()
lin=set()
for i in range(m):
  a,b=map(int,input().split())
  if(a==1):li1.add(b)
  elif(b==1):li1.add(a)
  elif(a==n):lin.add(b)
  elif(b==n):lin.add(a)
for i in li1:
  if(i in lin):
    print("POSSIBLE")
    sys.exit()
    
print("IMPOSSIBLE")
