from collections import deque

rev = 0
s = input()
queue = deque()
for c in s:
    queue.append(c)

q = int(input())
for i in range(q):
    cs = input().split()
    if cs[0] == '1':
        rev = 1 - rev
    else:
        if ((cs[1] == '1' and rev == 0) or (cs[1] == '2' and rev == 1)):
            queue.appendleft(cs[2])
        else:
            queue.append(cs[2])
r = ''.join(queue)
if rev == 1:
    print(r[::-1])
else:
    print(r)
