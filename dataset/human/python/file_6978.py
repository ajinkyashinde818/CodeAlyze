import collections
from functools import reduce

S = input()
Q = int(input())

deque = collections.deque(S)

is_reverse = False
for _ in range(Q):
    query = input().split()
    if query[0] == '1':
        is_reverse = not is_reverse
    else:
        if (query[1] == '1' and not is_reverse) or (query[1] =='2' and is_reverse):
            deque.appendleft(query[2])
        else:
            deque.append(query[2])
if is_reverse:
    deque.reverse()

res = list(deque)

print("".join(res))
