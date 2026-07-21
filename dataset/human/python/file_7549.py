from collections import deque

s=input()

d=deque()
for i in s: #10**5
  d.append(i)
  
v=1

q=int(input())

for i in range(q): #2*10**5
  a=input()
  if len(a)==1:
    if v:
      v=0
    else:
      v=1
  else:
    b,f,c=a.split()
    if f=="1":
      if v:
        d.appendleft(c)
      else:
        d.append(c)
    else:
      if v:
        d.append(c)
      else:
        d.appendleft(c)
        
if v:
  for i in range(len(d)):
    print(d[i],end="")
else:
  for i in range(len(d)):
    print(d[len(d)-1-i],end="")
    
print()
