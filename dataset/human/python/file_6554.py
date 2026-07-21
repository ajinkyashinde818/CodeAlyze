import sys
input = lambda: sys.stdin.readline().rstrip()
s=input()
q=int(input())
sign=1
F,B="",""
for i in range(q):
  Q=[str(i) for i in input().split()]
  if Q[0]=="1":
    sign*=-1
  else:
    f,c=Q[1:]
    if f=="1" and sign==1:
      F=c+F
    elif f=="2" and sign==-1:
      F=c+F
    else:
      B=B+c
ans=F+s+B
print(ans if sign==1 else ans[::-1])
