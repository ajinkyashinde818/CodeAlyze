from collections import deque
S=input()
Q=int(input())

X=deque(list(S))
f=1
for _ in range(Q):
    A=list(input().split())
    if A[0]=="1":
        f*=-1
    else:
        if A[1]=="1":
            if f==1:
                X.appendleft(A[2])
            else:
                X.append(A[2])
        else:
            if f==-1:
                X.appendleft(A[2])
            else:
                X.append(A[2])

if f==-1:
    X.reverse()

print("".join(X))
