from collections import deque

S = str(input())
Q = int(input())
t = 0

d = deque()
d.append(S)

for _ in range(Q):
    A = list(input().split())
    if A[0] == "1":
        if t == 0:
            t = 1
        else:
            t = 0

    elif (A[1] == "1" and t == 0) or (A[1] == "2" and t == 1):
        d.appendleft(A[2])
    else:
        d.append(A[2])

l = list(d)
ans = "".join(l)
if t == 1:
    ans = ans[::-1]
print(ans)
