from collections import deque
S = deque(input())
Q = int(input())
rev = False
for i in range(Q):
    query = input()
    if query[0] == '1':
        rev = not rev
    else:
        qtype = query[2]
        qstr = query[4]
        if qtype == "1":#先頭
            if not rev:
                S.appendleft(qstr)
            else:
                S.append(qstr)
        else:
            if not rev:
                S.append(qstr)
            else:
                S.appendleft(qstr)
if rev:
    print(*list(S)[::-1],sep="")
else:
    print(*S,sep="")
