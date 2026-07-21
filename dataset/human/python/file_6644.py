from collections import deque
S=input()
Q=int(input())
q=deque()
for i in S:
  q.append(i)
cnt=0
for i in range(Q):
  A=list(input().split())
  if int(A[0])==1:
    cnt+=1
  else:
    if int(A[1])==cnt%2+1:
      q.appendleft(A[-1])
    else:
      q.append(A[-1])
if (cnt%2)==0:
  for i in range(len(q)):
    print(q.popleft(),end='')
else:
  for i in range(len(q)):
    print(q.pop(),end='')
