from collections import deque

s = deque(input())

q = int(input())
r = 0
for _ in range(q):
    A = list(input().split())
    if A[0] == '1':
        r = (r + 1)%2
    else:
        if (A[1] == '1' and r % 2 == 0) or (A[1] == '2' and r % 2 == 1):
            s.appendleft(A[2])
        else:
            s.append(A[2])

if r == 1:
    s.reverse()
print("".join(s))
