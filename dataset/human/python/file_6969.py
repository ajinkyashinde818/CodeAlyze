from sys import stdin, stdout
from collections import deque

s = raw_input().strip()
q = input()
inp = stdin.readlines()

Q = deque(list(s))
rev = 0
for line in inp:
    x = line.strip().split()
    if x[0] == '1':
        rev ^= 3
    else:
        f = int(x[1])
        ch = x[2]
        f ^= rev
        if f == 1:
            Q.appendleft(ch)
        else:
            Q.append(ch)

l = []
while Q:
    if rev == 0: l.append(Q.popleft())
    else: l.append(Q.pop())

print ''.join(l)
