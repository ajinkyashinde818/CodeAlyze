from collections import deque as D 
d = D()
s=input();q=int(input())
ans=0
d.extend(list(s))
for i in range(q):
  k=list(input().split())
  if len(k)==1:
    ans=(ans+1)%2
  else:
    x,y,z=k
    y=(int(y)-1+ans)%2
    d.append(z) if y else d.appendleft(z)
print("".join(list(d)[::(-1)**ans]))
