from collections import deque
S = deque()
tmp = input()
for i in range(len(tmp)):
  S.append(tmp[i])
Q = int(input())
flag = True
for i in range(Q):
  string = input().split()
  if string[0] == '1':
    flag = not flag
  elif flag ^ (string[1] == '1'):
      S.append(string[2])
  else:
      S.appendleft(string[2])
if not flag:
  S.reverse()
for s in S:
  print(s, end='')
