from collections import deque
a = input()
c = input()
d = []
alist = list(a)
adeque = deque(a)
count = 0
for i in range(int(c)):
  e = input().split()
  d.append(e)
for i in range(int(c)):
  if d[i][0]=="1":
    count = count + 1
  else:
    if d[i][1] == "1" and count % 2 == 0:
      adeque.appendleft(d[i][2])
    elif d[i][1] == "2" and count % 2 == 1:
      adeque.appendleft(d[i][2])
    else:
      adeque.append(d[i][2])
alist = list(adeque)
if count % 2 == 1:
  l = len(alist)
  for x in range(int(l//2)):
    alist[x],alist[l-x-1] = alist[l-x-1],alist[x]
answer = "".join(alist)
print(answer)
