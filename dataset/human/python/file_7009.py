from collections import deque

S = deque(input())
n= int(input())
condition=True

for i in range(n):
  Q = [i for i in input().split()]
  if Q[0] =='1':
    if condition ==True:
      condition=False
    else:
      condition=True
  else:
    if Q[1]=='1':
      if condition ==True:
        S.appendleft(Q[2])
      else:
        S.append(Q[2])
    else:
      if condition==True:
        S.append(Q[2])
      else:
        S.appendleft(Q[2])
    #print(S)

if condition ==False:
  S.reverse()

for i in S:
  print(i, end='')
