import copy
N,G=map(int,input().split())
pc=[]
for i in range(N):
  pc.append(list(map(int,input().split())))
ans=10**10
for i in range(2**N):
  tmp=0
  tmp2=0
  l=[]
  for j in range(N):
    if i>>j&1:
      w=pc[j]
      p,c=w[0],w[1]
      tmp+=100*(j+1)*p+c
      tmp2+=p
    else:
      l.append(j)
  if tmp>=G:
    ans=min(ans,tmp2)
  else:
    pc_=copy.copy(pc)
    while tmp<G:
      index=l.pop(-1)
      w=pc_.pop(index)
      p,c=w[0],w[1]
      if 100*(index+1)*p+c+tmp<G:
        tmp+=(100*(index+1)*p+c)
        tmp2+=p
      elif 100*(index+1)*p+tmp<G<=100*(index+1)*p+c+tmp:
        tmp=G
        tmp2+=p
      else:
        val=(G-tmp)//(100*(index+1))
        if (G-tmp)%(100*(index+1))==0:
          tmp2+=val
        else:
          tmp2+=(val+1)
        tmp=G
    ans=min(ans,tmp2)
print(ans)
