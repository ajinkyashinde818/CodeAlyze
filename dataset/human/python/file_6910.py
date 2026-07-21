from collections import deque

S = list(input())
q = deque(S)
cnt_rev = 0
Q = int(input())
for _ in range(Q):
    T, *R = input().split()
    if T == "1":
        cnt_rev += 1
    else:
        F, c = R
        if cnt_rev % 2 == 0:
            if F == "1":
                q.appendleft(c)
            else:
                q.append(c)
        else:
            if F == "1":
                q.append(c)
            else:
                q.appendleft(c)

ans = list(q)
if cnt_rev % 2 == 1:
    ans.reverse()
print(*ans, sep="")
