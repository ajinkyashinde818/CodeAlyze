from collections import deque
S = input()
Q = int(input())
S = deque(S)
rev = False
for i in range(Q):
    T, *FC = input().split()
    if T == "1":
        rev = not rev
    else:
        if FC[0] == "1":
            if rev:
                S.append(FC[1])
            else:
                S.appendleft(FC[1])
        else:
            if rev:
                S.appendleft(FC[1])
            else:
                S.append(FC[1])

if rev:
    S.reverse()
print("".join(S))
