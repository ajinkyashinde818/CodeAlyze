import sys
input=lambda: sys.stdin.readline().rstrip()
n,k=map(int,input().split())
A=[int(i) for i in input().split()]
B=[0]
S=set()
S.add(0)
cur=A[0]-1
while True:
  if cur in S:
    break
  else:
    S.add(cur)
    B.append(cur)
    cur=A[cur]-1
d=len(B)
ind=B.index(cur)
if k<=ind:
  print(B[k]+1)
else:
  print(B[(k-ind)%(d-ind)+ind]+1)
