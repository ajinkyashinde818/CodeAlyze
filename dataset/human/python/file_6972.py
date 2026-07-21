from collections import deque
S = deque(input())
Q = int(input())
rev = 0
for i in range(Q):
  query = input()
  if query == "1": rev = 1 - rev 
  elif int(query[2]) + rev == 2: S.append(query[4])
  else:S.appendleft(query[4])
if rev == 1: S.reverse()  
print("".join(S))
