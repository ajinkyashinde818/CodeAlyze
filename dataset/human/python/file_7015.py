from collections import deque
S = list(input())
Q = int(input())
reverse = 1

d = deque()
for i in S:
  d.append(i)


for i in range(Q):
  temp = input().split()
  if temp[0] == "1":
    reverse = -reverse
  else:
    if temp[1] == "1" :
      if reverse == 1:
        d.appendleft(temp[2])
      else:
        d.append(temp[2])
    else:
      if reverse == 1:
        d.append(temp[2])
      else:
        d.appendleft(temp[2])
      
      
length = len(d)
for _ in range(length):
  temp = 0
  if reverse == 1:
    temp = d.popleft()
  else:
    temp = d.pop()
  print(temp, end="")
