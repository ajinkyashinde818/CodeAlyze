from collections import deque

S = deque(input())

Q = int(input())

c = False
for i in range(Q):
  *T, = map(str,input().split())
  if len(T) == 1:
    c = not c  
  elif (int(T[1]) == 1 and not c) or (int(T[1]) == 2 and c):
    S.appendleft(T[2])
  else:
    S.append(T[2])

print("".join(S) if not c else "".join(list(reversed(S))))
