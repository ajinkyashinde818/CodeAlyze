from collections import deque

s = input()
q = int(input())

t = deque(s)

reverse = False
for _ in range(q):
   query = input()
   if query[0] == '1':
      reverse = not reverse
   elif query[0] == '2':
      _, f, c = query.split()
      if f == '1':
         if reverse:
            t.append(c)
         else:
            t.appendleft(c)
      elif f == '2':
         if reverse:
            t.appendleft(c)
         else:
            t.append(c)

result = ''.join(t)
if reverse:
   result = result[::-1]
print(result)
