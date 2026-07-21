from collections import deque

s = input()
q = deque(list(s))

while q:
  if len(q) >= 5:
    subs = q.popleft()+q.popleft()+q.popleft()+q.popleft()+q.popleft()
    if subs != 'erase' and subs != 'dream':
      print('NO')
      exit()
    if subs == 'erase' and len(q) != 0 and q[0] == 'r':
      q.popleft()
    if subs == 'dream' and len(q) == 2 and q[0]+q[1] == 'er':
      q.popleft()
      q.popleft()
    if subs == 'dream' and len(q) >= 3 and q[0]+q[1] == 'er' and q[2] != 'a':
      q.popleft()
      q.popleft()
  else:
   
    print('NO')
    exit()
    
print('YES')
