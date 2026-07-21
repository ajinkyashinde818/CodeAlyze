from collections import deque
S = input()
Q = int(input())

st = True
deq = deque(S)
for _ in range(Q):
    Query = input().split()
    if Query[0] == '1':
        st = not st
    else:
        if (Query[1] == '1') ^ st:
            deq.append(Query[2])
        else:
            deq.appendleft(Query[2])
if st:
    print(''.join(deq))
else:
    print(''.join(reversed(deq)))
