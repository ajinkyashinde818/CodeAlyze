from collections import deque

s = list(input())
s = deque(s)
q = int(input())
flag = ''
count = 0
for i in range(q):
    que = list(map(str,input().split()))
    if que[0] == "1":
        count += 1
        if flag == 'one':
          flag = ''
        else:
          flag = 'one'
    else:
        if que[1] == '1':
            if flag == 'one':
                s.append(que[2])
            else:
                s.appendleft(que[2])
        elif que[1] == '2':
            if flag == 'one':
                s.appendleft(que[2])
            else:
                s.append(que[2])
if count % 2 == 0:
  for i in s:
    print(i,end="")
else:
  for i in reversed(s):
    print(i,end="")
