from collections import deque
S = input()
d = deque([S[i] for i in range(len(S))])
Q = int(input())
bol = 0
for i in range(Q):
    a = input().split()
    if a[0] == "1":
        bol = 0 if bol else 1
    elif a[1] == "1":
        if not bol:
            d.appendleft(a[2])
        else:
            d.append(a[2])
    else:
        if not bol:
            d.append(a[2])
        else:
            d.appendleft(a[2])
print("".join(d) if not bol else "".join(reversed(d)))
