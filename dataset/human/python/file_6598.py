from collections import deque
import sys
input = sys.stdin.readline

S_deque = list(input())
S_deque = deque(S_deque[:-1])
Q = int(input())

top_flag = 1 # 0なら末尾、1なら最初

for _ in range(Q):
  item = list(input().split())
  if item[0] == '1':
    if top_flag == 0:
      top_flag = 1
    else:
      top_flag = 0

  else:
    in_flag = top_flag + int(item[1])
    if in_flag % 2 == 0:
      S_deque.appendleft(item[2])
    else:
      S_deque.append(item[2])

if top_flag == 0:
  S_deque.reverse()
else:
  pass

print(''.join(S_deque))
