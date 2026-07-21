import sys
input=sys.stdin.readline

n,m=map(int,input().split())
boola=[False]*(n+1)
boolb=[False]*(n+1)
for _ in range(m):
  a,b=map(int,input().split())
  if b==n: boola[a]=True
  if a==1: boolb[b]=True

for i in range(2,n):
  if boola[i] and boolb[i]:
    print("POSSIBLE")
    exit()
print("IMPOSSIBLE")
