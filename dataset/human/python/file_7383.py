from collections import deque

s=deque(input())
q=int(input())
qq=[list(input().split()) for i in range(q)]

rl=1
fleft=deque()
fright=deque()

for i in qq:
  if i[0]=='1':
    rl*=-1
  else:
    if i[1]=='1':
      if rl==1:
        fleft.appendleft(i[2])
      else:
        fright.append(i[2])
    else:
      if rl==1:
        fright.append(i[2])
      else:
        fleft.appendleft(i[2])

fleft.reverse()

s.extendleft(fleft)
s.extend(fright)

if rl==-1:
  s.reverse()

print(''.join(s))
