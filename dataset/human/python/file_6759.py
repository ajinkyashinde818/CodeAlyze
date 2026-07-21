from collections import deque
a = list(input())
a = deque(a)
re = 0
for i in range(int(input())):
  b = input().split()
  if b[0] == "1":
    re = (re+1)%2
  else:
    if (re and b[1] == "2") or (not(re) and b[1] == "1"):
      a.appendleft(b[2])
    else:
      a.append(b[2])
a = list(a)
if re:
  a = a[::-1]
print("".join(a))
