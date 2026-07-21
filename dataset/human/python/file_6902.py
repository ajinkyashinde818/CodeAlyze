from collections import deque

s = input()
Q = int(input())

dq = deque(list(s))

reversed_state = False
  
for q in range(Q):
  query = input().split()
  if len(query) == 1:
    reversed_state = not reversed_state
  else:
    T,F,c = list(query)
    if F == '1':
      if reversed_state == False:
      	dq.appendleft(c)
      else:
        dq.append(c)
    else:
      if reversed_state == False:
        dq.append(c)
      else:
        dq.appendleft(c)
      
print(''.join(dq)) if reversed_state == False else print(''.join(list(dq)[::-1]))
