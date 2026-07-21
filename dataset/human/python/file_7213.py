from collections import deque
S=deque([c for c in input()])
Q=int(input())
flg=True
for i in range(Q):
    l=[a for a in input().split()]
    if l[0]=="1": 
        flg=not flg
    else:
        if l[1]=="1":
            if flg:
                S.appendleft(l[2])
            else:
                S.append(l[2])
        else:
            if flg:
                S.append(l[2])
            else:
                S.appendleft(l[2])
print("".join(S) if flg else "".join(list(reversed(S))))
