from collections import deque
s = input()
rev = s[::-1]
curs = [deque(list(s)), deque(list(rev))]
f = 0
b = 1
q = int(input())
for _ in range(q):
    stuff = input().split()
    if stuff[0] == '1':
        f, b = b, f
    else:
        op, fi, c = stuff
        fi = int(fi)
        if fi == 1:
            curs[f].appendleft(c)
            curs[b].append(c)
        else:
            curs[f].append(c)
            curs[b].appendleft(c)
print(''.join(curs[f]))
