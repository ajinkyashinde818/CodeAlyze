from collections import deque
S=deque(list(input()))
Q=int(input())
l=list(input().split() for i in range(Q))
a=0
for j in l:
  if j[0]=="1":
      a+=1
  else:
    if j[1]=="1":
        if a %2==0:
            S.appendleft(j[2])
        else:
            S.append(j[2])
    else:
        if a %2==1:
            S.appendleft(j[2])
        else:
            S.append(j[2])
        
if a%2==0:
    print("".join(S))
else:
    S.reverse()
    print("".join(S))
