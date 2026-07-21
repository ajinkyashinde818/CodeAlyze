from collections import deque

ss = input()
q = int(input())
s = deque()

for i in range(len(ss)) :
  s.append(ss[i])

r = 0
for i in range(q) :
  t = list(map(str,input().split()))
  if t[0] == '1' :
    r += 1
  if t[0] == '2' :
    f = t[1] ; c = t[2]
    if r%2 == 0 :
      if f == '1' :
        s.appendleft(c)
      else :
        s.append(c)
    else :
      if f == '2' :
        s.appendleft(c)
      else :
        s.append(c)
        
if r%2 == 1 :
  s.reverse()
  
print(*s,sep='')
