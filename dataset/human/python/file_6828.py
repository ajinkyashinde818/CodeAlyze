from collections import deque
S=input()
N=int(input())
q = deque()
A = [input().split()]
for n in range(N-1):
  A.append(input().split())
for s in S:
  q.append(s)
top = True
for n in range(N):
  if A[n][0]=="1":
    top = not top
  elif A[n][1]=="1" and top or A[n][1]=="2" and not top:
    q.appendleft(A[n][2])
  else:
    q.append(A[n][2])
T = ""
while len(q)>0:
  if top:
    T+=q.popleft()
  else:
    T+=q.pop()
print(T)
