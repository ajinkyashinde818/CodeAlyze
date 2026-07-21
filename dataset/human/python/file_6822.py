import collections
S = collections.deque(list(input()))
Q = int(input())
spin = False
for i in range(Q):
    temp = list(input().split())
    if temp[0] == "1":
        spin = not spin
    else:
        if spin:
            if temp[1] == "1":
                S.append(temp[2])
            else:
                S.appendleft(temp[2])
        else:
            if temp[1] == "1":
                S.appendleft(temp[2])
            else:
                S.append(temp[2])

res = ""
if spin:
    S.reverse()
    print("".join(S))
else:
    print("".join(S))
