from collections import deque
N,K=map(int,input().split())
A= [0]+list(map(int,input().split()))
t=1
r=set()
q=deque([])
loop_flag=False

if K<=N:
  for i in range(1,K+1):
    t = A[t]
  print(t)
else:
  for i in range(K):
    #print(i,r)
    q.append(t)
    if t not in r:
      r.add(t)
      t=A[t]
    else:
      break
  start=0
  while q:
    a=q.popleft()
    if a==q[-1]:         
      loop_leng=i-start
      break
    start +=1
  
  K -=start
  K = K%loop_leng
  #print(start,loop_leng)
  
  t=1
  for i in range(1,start+1):
    #print(t,A[t])
    t = A[t]
  for i in range(1,K+1):
    t = A[t]  
  print(t)
