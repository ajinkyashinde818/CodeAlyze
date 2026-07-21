from collections import deque


s = deque(list(input()))
n = int(input())
flag = True
for _ in range(n):
    _input = input().split()
    if len(_input) == 1:
        if flag == True:
            flag = False
        else:
            flag = True
    else:
        if (_input[1] == '1' and flag == True) or (_input[1] == '2' and flag == False):
            s.appendleft(_input[2])
        else:
            s.append(_input[2])

if flag == True:
    print("".join(s))
else:
    print("".join([x for x in reversed(s)]))
