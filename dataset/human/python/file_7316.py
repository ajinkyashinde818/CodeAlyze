from collections import deque

s=list(input())
q=int(input())
d = deque(s)
reverse=False

for i in range(q):
  qs=list(input().split())
  if qs[0]=='1':
    reverse=not reverse
  else:
    if qs[1]=='1':
      d.appendleft(qs[2]) if not reverse else d.append(qs[2])
    else:
      d.append(qs[2]) if not reverse else d.appendleft(qs[2])
#  print(d)
if reverse:
  d.reverse()
print("".join(d))
