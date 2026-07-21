from collections import defaultdict
xs,ys,xt,yt=map(int,input().split())
P=[]
inf=float("inf")
P.append((xs,ys,0))
P.append((xt,yt,0))
N=int(input())
for i in range(N):
  x,y,r=map(int,input().split())
  P.append((x,y,r))

G=defaultdict(int)
for i in range(N+2):
  for j in range(N+2):
      x1,y1,r1,x2,y2,r2=P[i][0],P[i][1],P[i][2],P[j][0],P[j][1],P[j][2]
      d=((x1-x2)**2+(y1-y2)**2)**(1/2)
      G[(i,j)]=max(0,d-r1-r2)

def dijkstra():
  d=[inf]*(N+2)
  d[0]=0
  used=[False]*(N+2)
  
  while True:
    v=-1
    for i in range(N+2):
      if used[i]==False and (v==-1 or d[i]<d[v]):
        v=i
    if v==-1:
      break
    used[v]=True
    for j in range(N+2):
      d[j]=min(d[j],d[v]+G[(v,j)])    
  return d[1]
print(dijkstra())
