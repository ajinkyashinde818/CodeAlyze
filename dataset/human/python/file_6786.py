from collections import deque

s = list(input())
q = int(input())

qs = [list(input()) for _ in range(q)]

d = deque([])

for c in s:
    d.append(c)

flag_r = False

for qq in qs:
    if qq[0] == '1':
        flag_r = not flag_r
    else:
        if flag_r:
            if qq[2] == '1':
                d.append(qq[4])
            else:
                d.appendleft(qq[4])
        else:
            if qq[2] == '1':
                d.appendleft(qq[4])
            else:
                d.append(qq[4])

if flag_r:
    d.reverse()

print(''.join(d))
