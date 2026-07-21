from collections import deque
S = input()
Q = int(input())
 
alpha_map = {chr(i):i for i in range(97,123)}
alpha_map_inv = {i:chr(i) for i in range(97,123)}
a = deque()
for s in S:
  a.append(s)
reversed = False
 
for _ in range(Q):
  query = list(map(str, input().split()))
  if query[0] == '1':
    if reversed:
      reversed = False
    else:
      reversed = True
  else:
    if (query[1] == '1')&(not reversed):
      a.appendleft(query[2])
    elif (query[1] == '2')&(reversed):
      a.appendleft(query[2])
    else:
      a.append(query[2])
if reversed:
  a.reverse()
print(''.join(list(a)))
