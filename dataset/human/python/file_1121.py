from collections import deque

n=int(input())
A=[int(i) for i in input().split()]
B=[int(i) for i in input().split()]
ans=[-1 for i in range(n)]

newB=[]
cnt=1
old=B[0]
for i in range(1,n):
    if old!=B[i]:
        newB.append((old,cnt))
        cnt=1
        old=B[i]
    else:
        cnt+=1
else:
    newB.append((old,cnt))
B=deque(newB)

def firstDec():
    now=B.popleft()
    if now[1]>1:
        B.appendleft((now[0],now[1]-1))

tori=0

for i in range(n):
    if B[0][0]!=A[i]:
        ans[i]=B[0][0]
        firstDec()
        continue

    B.rotate(-1)
    if B[0][0]!=A[i]:
        ans[i]=B[0][0]
        firstDec()
        continue
    
    OK=False
    while tori<i:
        if ans[tori]!=B[0][0] and A[tori]!=B[0][0]:
            ans[i]=ans[tori]
            ans[tori]=B[0][0]
            OK=True
            break
        B.rotate()
        if ans[tori]!=B[0][0] and A[tori]!=B[0][0]:
            ans[i]=ans[tori]
            ans[tori]=B[0][0]
            OK=True
            break
        tori+=1
    if OK:
        continue
    
    print("No")
    break
else:
    print("Yes")
    print(" ".join([str(num) for num in ans]))
