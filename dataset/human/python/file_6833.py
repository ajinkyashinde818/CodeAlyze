from collections import deque
S=input()
Q=int(input())
front=deque()
back=deque()

reverse=False
for i in range(Q):
  ins=input()
  if len(ins)==1:
    if reverse:
      reverse=False
    else:
      reverse=True
  else:
    q,f,c=map(lambda x: x, ins.split())
    
    if f=="1":
      if reverse:
        back.append(c)
        
      else:
        front.appendleft(c)
        
    else:
      if reverse:
        front.appendleft(c)
      else:
        back.append(c)
        
back=list(back)
front=list(front)
if reverse:
  back=back[::-1]
  front=front[::-1]
  S=list(S)[::-1]
  print("".join(back)+"".join(S) +"".join(front))
else:
  print("".join(front)+S+"".join(back))
  
#print(reverse)
#print(front, back)
