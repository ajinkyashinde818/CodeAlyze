import heapq
from collections import deque
s = input()
s_list = list(s)
s_list = deque(s_list)
q = int(input())
q_list = []
for i in range(q):
  q_list.append(list(map(str,input().split())))
check = 0
for list_ in q_list:
  if int(list_[0]) == 1:
    check += 1
  if int(list_[0]) == 2:
    if (int(list_[1]) + check) % 2 ==1:
      s_list.appendleft(list_[2])
    else:
      s_list.append(list_[2])
s_list = list(s_list)
if check % 2 == 1:
  s_list = s_list[::-1]
print("".join(s_list))
