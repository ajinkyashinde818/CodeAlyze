from collections import deque

S = input()
Q = int(input())
a = deque(S)

flag = 0

for i in range(Q):
  A = input().split()
  if A[0] == "1":
    if flag == 0:
      flag = 1
    else:
      flag = 0
  else:
    if A[1] == "1" and flag == 0 or A[1] == "2" and flag == 1:      
      a.appendleft(A[2])
    else:
      a.append(A[2])

if flag == 1:
  a.reverse()
print("".join(a))
