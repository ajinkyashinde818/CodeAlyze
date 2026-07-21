from collections import deque
S = deque(list(input()))
Q = int(input())
f = 0
for _ in range(Q):
  a, *b = input().split()
  f += int(a)
  if a == "2":
    if (int(b[0]) + f) % 2 == 1 :
      S.appendleft(b[1])
    else:
      S.append(b[1])
D = list(S)
print ("".join(D) if f % 2 == 0 else "".join(D[::-1]))
