from collections import deque
S=deque(input())
Q=int(input())
rev=False
for i in range(Q):
    A=input().split()
    if A[0]=="1":
        if rev==False:rev=True
        else:rev=False
    else:
        if rev==False:
            if A[1]=="1":
                S.appendleft(A[2])
            else:
                S.append(A[2])
        else:
            if A[1]=="1":
                S.append(A[2])
            else:
                S.appendleft(A[2])
if rev:
    S.reverse()
print(*S,sep="")
