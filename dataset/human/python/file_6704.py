from collections import deque

S = input()
Q = int(input())

cur = 1
d = deque([S])

for _ in range(Q):
    ins = input().split()
    if len(ins) == 1:
        cur = 2 if cur == 1 else 1
    else:
        _, f, c = ins
        f = int(f)
        if cur == f == 1 or cur == f == 2:
            d.appendleft(c)
        else:
            d.append(c)

if cur == 1:
    print("".join(d))
else:
    temp = "".join(d)
    print(temp[::-1])
