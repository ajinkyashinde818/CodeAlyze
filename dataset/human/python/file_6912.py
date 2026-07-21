from collections import deque
S = input()
deque = deque([s for s in S])
Q = int(input())
rev_flag = 0
for _ in range(Q):
    q = list(map(str, input().split()))
    if len(q) == 1:
        if rev_flag:
            rev_flag = 0
        else:
            rev_flag = 1
    else:
        if q[1] == "1":
            if rev_flag:
                deque.append(q[2])
            else:
                deque.appendleft(q[2])
        else:
            if rev_flag:
                deque.appendleft(q[2])
            else:
                deque.append(q[2])
if rev_flag:
    print("".join(deque)[::-1])
else:
    print("".join(deque))
