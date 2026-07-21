import sys

sys.setrecursionlimit(100000)

def f(a):
  global R,G,B,N,ans,Rm,Gm,Bm

  for b in range(N-R*a+1):
    cmod=(N-R*a-G*b)%B
    c=(N-R*a-G*b)//B
    if cmod==0 and  c>=0:
      ans+=1
    elif c<0:
      break

  if a>0:
    f(a-1)


R,G,B,N=list(map(int,input().split(" ")))

ans=0

f(N//R+1)

print(ans)
