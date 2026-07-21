from collections import deque
s = input()

q = int(input())
s = deque(s)
r = False
for _ in range(q):
    cmd = input()
    if cmd[0] == '1':
        r = not r
    else:
        cmd, f, c = cmd.split()
        if (f == '2' and not r) or (f=='1' and r):
            s.append(c)
        else:
            s.appendleft(c)
if r:
    s.reverse()
print(''.join(s))
