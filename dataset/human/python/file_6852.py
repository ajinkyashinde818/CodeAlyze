from collections import deque
t=input()
s=deque(t)
q=int(input())
flag=True
for i in range(q):
  ques=list(input().split())
  if ques[0]=="1":
    flag=not flag
    continue
  if ques[1]=="1":
    if flag:
      s.appendleft(ques[2])
    else:
      s.append(ques[2])
  else:
    if flag:
      s.append(ques[2])
    else:
      s.appendleft(ques[2])
if flag==False:
    print(''.join(reversed(list(s))))
else:
    print(''.join(list(s)))
