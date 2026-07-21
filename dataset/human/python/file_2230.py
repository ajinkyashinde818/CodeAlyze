from collections import deque
d,g=map(int,input().split())
pc=[list(map(int,input().split())) for _ in range(d)]
ans=10**7
for i in range(2**d):
  cnt=0
  c=0
  l=deque([])
  for j in range(d):
    if (i>>j)&1:
      cnt+=(j+1)*100*pc[j][0]+pc[j][1]
      c+=pc[j][0]
      l.appendleft([1,j])
    else:
      l.appendleft([0,j])
  if cnt<g:
    for n,m in l:
      if n==0:
        if g-(cnt+pc[m][0]*(m+1)*100)<=0:
          if (g-cnt)%((m+1)*100)==0:     
            c+=(g-cnt)//((m+1)*100)
            cnt=g
          else:
            c+=(g-cnt)//((m+1)*100)+1
            cnt=g
        break
  if cnt>=g:
    ans=min(ans,c)
print(ans)
