from collections import deque

S = deque(input())
Q = int(input())

rev_stetus = False
for _ in range(Q):
    ipt = input().split()
    if ipt[0] == "1":
        rev_stetus = not rev_stetus
    else:
        f = int(ipt[1])
        c = ipt[2]
        if rev_stetus:
            if f == 1:
                S.append(c)
            else:
                S.appendleft(c)
        else:
            if f == 1:
                S.appendleft(c)
            else:
                S.append(c)

if rev_stetus:
    S.reverse()
    print("".join(S))
else:
    print("".join(S))
