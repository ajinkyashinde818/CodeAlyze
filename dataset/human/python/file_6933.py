from collections import deque

S = input()
Q = int(input())
flag_reversed = False
ret = deque(S)

for _ in range(Q):
    temp = input()
    if (len(temp) < 2):
        flag_reversed = not flag_reversed
    else:
        T, F, C = [x for x in temp.split(" ")]
        F = int(F)
        add_begin = True
        if (F == 2):
            add_begin = False
        if (flag_reversed):
            add_begin = not add_begin
        if (add_begin):
            ret.appendleft(C)
        else:
            ret.append(C)

ret = ''.join(ret)

if (flag_reversed):
    ret = ''.join(reversed(ret))
print(ret)
