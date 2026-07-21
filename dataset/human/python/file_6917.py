from collections import deque

S = deque(list(input()))
Q = int(input())
r = False
left = deque()
right = deque()
for i in range(Q):
    q = input().split()
    if q[0] == "1":
        r = not r
    else:
        f, c = q[1:]
        if f == "1":
            if r:
                right.append(c)
            else:
                left.appendleft(c)
        else:
            if r:
                left.appendleft(c)
            else:
                right.append(c)

S, left, right = map(list, (S, left, right))
left.extend(S)
left.extend(right)
print("".join(left[::-1] if r else left))
