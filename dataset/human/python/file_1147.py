import random
N=int(input())
A=[int(i) for i in input().split()]
B=[int(i) for i in input().split()]
a=[0 for i in range(N+1)]
b=[0 for i in range(N+1)]
for i in range(N):
    a[A[i]]+=1
    b[B[i]]+=1
if max([a[i]+b[i] for i in range(1,N+1)])<=N:
    print("Yes")
else:
    print("No")
    exit()
B=B[::-1]
point=0
for i in range(N):
    if A[i]==B[i]:
        point+=1
while(point>0):
    x=random.randrange(N)
    y=random.randrange(N)
    if x==y:
        continue
    before=0
    after=0
    if A[x]==B[x]:
        before+=1
    if A[y]==B[y]:
        before+=1
    if A[x]==B[y]:
        after+=1
    if A[y]==B[x]:
        after+=1
    if before>after:
        B[x],B[y]=B[y],B[x]
        point=point+after-before
print(*B)
