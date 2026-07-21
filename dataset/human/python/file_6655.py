from collections import deque

S = input()
pre, post = deque(), deque()
Q = int(input())
reversed = False
for _ in range(Q):
  query = input().split()
  if query[0] == '1':
    reversed = not reversed
    pre, post = post, pre
  else:  # query[0] == 2
    F, C = query[1:]
    if F == '1':
      if reversed:
        pre.append(C)
      else:
        pre.appendleft(C)
    else:  # F == '2'
      if reversed:
        post.appendleft(C)
      else:
      	post.append(C)
if reversed:
  print(''.join(pre)[::-1] + S[::-1] + ''.join(post)[::-1])
else:
  print(''.join(pre) + S + ''.join(post))
