from collections import deque
import sys

flg1 = 1
s = input()
ll = deque()
lr = deque()
for _ in range(int(input())):
    q = sys.stdin.readline().rstrip()
    if q == "1":
        flg1 *= -1
    else:
        q = list(q.split())
        flg2 = 1 if q[1] == "1" else -1
        if flg1 * flg2 == 1:
            ll.appendleft(q[2])
        else:
            lr.append(q[2])

ans = "".join(ll) + s + "".join(lr)
print((ans[::-1], ans)[flg1 == 1])
