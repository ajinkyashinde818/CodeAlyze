from collections import deque
S=input()
N=int(input())
q=deque([S[i] for i in range(len(S))])

c=0
for i in range(N):
  A=list(map(str,input().split()))
  if A[0]=='1':
     c+=1
     c%=2
  else:
     if (c+int(A[1]))%2==1:
       q.appendleft(A[2])
     if (c+int(A[1]))%2==0:
       q.append(A[2])
s=''
if c==0:
  for i in range(len(q)):
    r=q.popleft()
    s+=r
if c==1:
  for i in range(len(q)):
    d=q.pop()
    s+=d
print(s)
