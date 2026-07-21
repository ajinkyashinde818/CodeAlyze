from collections import deque
S = list(input())
Q = int(input())
num = 1
q = deque(S)
for _ in range(Q):
    L = [i for i in input().split()]
    if len(L) == 1:
        num += 1
        num %= 2
    else:
        if int(L[1])%2 == num:
            q.appendleft(L[2])
        else:
            q.append(L[2])

ans = list(q)
if num == 0:
    ans.reverse()
print("".join(ans))
