from collections import deque
from itertools import islice

S = input()

result = deque(S)


def input_str(line):
    r = line.split()
    if len(r) == 1:
        return int(r[0]), None, None
    else:
        return int(r[0]), int(r[1]), r[2]


reverse_flag = False

for _ in range(int(input())):
    Q, F, C = input_str(input())
    if Q == 1:
        reverse_flag ^= True
    if Q == 2:
        if reverse_flag:
            if F == 1:
                result.append(C)
            else:
                result.appendleft(C)
        else:
            if F == 1:
                result.appendleft(C)
            else:
                result.append(C)

if reverse_flag:
    result.reverse()
print(''.join(result))
