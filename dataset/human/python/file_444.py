def minus(n):
  if n>=0:
    return 0
  else:
    return 1
N=int(input())
L=list(map(int,input().split()))
c=sum(list(map(minus,L)))
if c%2==0:
  t=sum(list(map(abs,L)))
  print(t)
else:
  L=list(map(abs,L))
  print(sum(L)-min(L)*2)
