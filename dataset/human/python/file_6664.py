from collections import deque
S = input()
Q = int(input())

n = S
mode = 0
operations = []
deq = deque(n)
for i in range(Q):
    operations.append(input().split())
for op in operations:
    if op[0] == "1":
        mode += 1
        mode %= 2
    elif int(op[1]) + mode == 2:
        deq.append(op[2])
    else:
        deq.appendleft(op[2])
if mode == 0:
    print("".join(deq))
else:
    print("".join(reversed(deq)))
