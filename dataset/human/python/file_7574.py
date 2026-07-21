from collections import deque

s = input()
q = int(input())
Q = [list(map(str, input().split())) for i in range(q)]

ans = deque(s)

reverse_num = 0
for i in range(q):
  if int(Q[i][0]) == 1:
    reverse_num += 1
  else:
    if int(Q[i][1]) == 1:
      if reverse_num % 2 == 0:
        ans.appendleft(Q[i][2])
      else:
        ans.append(Q[i][2])
    else:
      if reverse_num % 2 != 0:
        ans.appendleft(Q[i][2])
      else:
        ans.append(Q[i][2])

res = ''
if reverse_num % 2 == 0: 
  for i in range(len(ans)):
    res += ans.popleft()
  print(res)
else:
  for i in range(len(ans)):
    res += ans.pop()
  print(res)
