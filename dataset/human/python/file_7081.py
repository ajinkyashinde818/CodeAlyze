from collections import deque

S=input()
Q=int(input())
r_flag=False
ans=deque((S))
for i in range(Q):
  Qu=input().split()
  if Qu[0]=="1":
    r_flag=not r_flag
  else:
    if Qu[1]=="1":
      if r_flag==True:
        ans.append(Qu[2])
      else:
        ans.appendleft(Qu[2])
    else:
      if r_flag==True:
        ans.appendleft(Qu[2])
      else:
        ans.append(Qu[2])
ans=list(ans)
print("".join(ans) if r_flag==False else "".join(ans[::-1]))
