import math
xs,ys,xt,yt=map(int,input().split())
N=int(input())

xyrlist=[]
for _ in range(N):
  x,y,r=map(int,input().split())
  xyrlist.append((x,y,r))
  
graph=[[] for _ in range(N+2)]
#s->t
graph[0].append((N+1,math.sqrt((xt-xs)**2+(yt-ys)**2)))

#s->xi
for i in range(N):
  xi,yi,ri=xyrlist[i]
  if (xs-xi)**2+(ys-yi)**2<=ri**2:
    graph[0].append((i+1,0))
  else:
    graph[0].append((i+1,math.sqrt((xs-xi)**2+(ys-yi)**2)-ri))

#xi<->xj
for i in range(N):
  xi,yi,ri=xyrlist[i]
  for j in range(i+1,N):
    xj,yj,rj=xyrlist[j]
    if (xj-xi)**2+(yj-yi)**2<=(ri+rj)**2:
      graph[i+1].append((j+1,0))
      graph[j+1].append((i+1,0))
    else:
      graph[i+1].append((j+1,math.sqrt((xj-xi)**2+(yj-yi)**2)-ri-rj))
      graph[j+1].append((i+1,math.sqrt((xj-xi)**2+(yj-yi)**2)-ri-rj))

#xi->t
for i in range(N):
  xi,yi,ri=xyrlist[i]
  if (xt-xi)**2+(yt-yi)**2<=ri**2:
    graph[i+1].append((N+1,0))
  else:
    graph[i+1].append((N+1,math.sqrt((xt-xi)**2+(yt-yi)**2)-ri))
#print(graph)
    
import heapq
def dijkstra_heap(s):
  #始点sから各頂点への最短距離
  dist=[float("inf")]*size_v
  used=[False]*size_v
  dist[s]=0
  used[s]=True

  hq_edge=[]
  for v,w in graph[s]:
    heapq.heappush(hq_edge,(w,v))

  while hq_edge:
    min_w,min_v=heapq.heappop(hq_edge)
    #まだ使われてない頂点の中から最小の距離のものを探す
    if used[min_v]:
      continue

    dist[min_v]=min_w
    used[min_v]=True
    #prev[min_v]=ei #第3引数
    for v,w in graph[min_v]:
      if not used[v]:
        heapq.heappush(hq_edge,(min_w+w,v))

  return dist

size_v=N+2
dist=dijkstra_heap(0)
#print(dist)
print(dist[N+1])
