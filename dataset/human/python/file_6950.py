import sys
input = sys.stdin.readline
from collections import deque

S = input().rstrip()
S = deque(S)
Q = int(input())
Que = (input().rstrip() for _ in range(Q))

flag = 0 #0:そのまま 1:反転
for elem in Que:
  if elem[0] == '1':
    flag ^= 1
  else:
    s = int(elem[2])
    if s == 1 and flag == 0:
      S.appendleft(elem[4])
    elif s == 2 and flag == 0:
      S.append(elem[4])
    elif s == 1 and flag == 1:
      S.append(elem[4])
    else:
      S.appendleft(elem[4])

if flag == 1:
  S.reverse()
print(''.join(S))
