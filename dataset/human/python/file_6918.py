from collections import deque

S=deque(str((input())))
Q=int(input())
t=0
for _ in range(Q):
    T=list(map(str,input().split()))
    if T[0]=="1":
        t+=1
    else:
        if (T[1]=="1" and t%2 == 0) or (T[1]=="2" and t%2 != 0):
            S.appendleft(T[2])
        else:
            S.append(T[2])


if t%2 != 0:
    S.reverse()

print("".join(S))
