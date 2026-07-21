import sys
d, g = map(int, input().split())
g=g//100
pc=[[0,0]]
ans=sys.maxsize
for i in range(d):
  pc.append(list(map(int,input().split())))

for i in range(2**d):
  temp=0
  cnt=0
  for j in range(1,d+1):
    p=pc[j][0]
    c=pc[j][1]//100
    if (i>>(j-1)) & 1:
      temp+=(p*j+c)
      cnt+=p
  if temp >= g:
    ans=min(ans,cnt)
  else:
    for j in range(d,0,-1):
      p=pc[j][0]
      if (not ((i>>(j-1)) & 1)):
        if temp + j*p >= g:
          h=(((g-temp)//j)+1)
          if (g-temp)%j == 0:
            h-=1
          cnt+=h
          ans=min(ans,cnt)
        break
print(ans)
