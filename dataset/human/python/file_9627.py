from collections import deque

n,k = map(int,input().split())
li = list(map(int,input().split()))

for i,l in enumerate(li):
  li[i]-=1

done = [0]*n
root = []
que  = deque()

done[0] = 1
root.append(0)
que.append(li[0])


while(len(que)!=0 and len(root)<k+1):
  v = que.pop()
  
  if done[v]!=0:
    root.append(v)
    break

  done[v] = 1
  root.append(v)
  que.append(li[v])

if len(root)==k+1:
  print(root[-1]+1)
else:
  fidx = root.index(root[-1])
  lidx = len(root)-1
  lp   = lidx-fidx

  cnt = (k-fidx)%lp

  if cnt==0:
    print(root[-1]+1)
  else:
    que.append(root[-1])
    for i in range(cnt):
      v = que.pop()
      que.append(li[v])
    print(que.pop()+1)
