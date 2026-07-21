from collections import deque
S=list(input())
Q=int(input())
query=[]
reverseflg=False
S=deque(S)

for i in range(Q):
  query.append(list(input().split()))

for q in range(Q):
  if query[q][0]=="1":
    reverseflg= not reverseflg
  
  if query[q][0]=="2":
    if query[q][1]=="1":
      if reverseflg== False:
        S.appendleft(query[q][2])
      else:
        S.append(query[q][2])
    
    else:
      if reverseflg== False:
        S.append(query[q][2])
      else:
        S.appendleft(query[q][2])

if reverseflg==True:
  S.reverse()
  
print(''.join(S))
