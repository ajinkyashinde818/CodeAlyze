from collections import deque
n,m = map(int,input().split())

tree = [[] for i in range(n)]
for i in range(m):
  tmp_a,tmp_b = map(int,input().split())
  tree[tmp_a-1].append(tmp_b-1)
  tree[tmp_b-1].append(tmp_a-1)
def bfs():
  q = deque()
  visited =[False]*n
  visited[0]=True
  for elem in tree[0]:
    q.append([elem,1])
  while q:
    i,cnt = q.popleft()
    if i == n-1 and cnt <=2 :
      print("POSSIBLE")
      exit()
    if not visited[i]:
      visited[i] = True
      if cnt<=1:
        for elem in tree[i]:
          q.append([elem,cnt+1])

bfs()
print("IMPOSSIBLE")
