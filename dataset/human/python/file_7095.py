from collections import deque

s = deque(input())
q = int(input())
rev_f = True

for i in range(q):
    cmd = input().split()
    if cmd[0] == '1':
        rev_f = (False if rev_f else True)
    else:
        f = cmd[1]
        c = cmd[2]
        if (rev_f and f == '1') or (not rev_f and f != '1'):
            s.appendleft(c)
        else:
            s.append(c)

print(''.join(s if rev_f else reversed(s)))
