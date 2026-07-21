from collections import deque
H=deque(input())
Q=int(input())
reverse=False

A,B="",""
for _ in range(Q):
    T=input()
    if T[0]=="1":
        reverse=not reverse
    else:
        _,F,C=T.split()

        if ((not reverse) and F=="1") or (reverse and F=="2"):
            H.appendleft(C)
        else:
            H.append(C)

if reverse:
    H.reverse()

for s in H:
    print(s,end="")
print()
