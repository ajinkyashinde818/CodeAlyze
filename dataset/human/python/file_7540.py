from collections import deque
s = input()
q = int(input())
flip = 0
d = deque(list(s))
for i in range(q):
    query = input().split()
    if query[0] == '1':
        flip ^= 1
    else:
        f = int(query[1]) - 1
        c = query[2]
        if f ^ flip == 1:
            d.append(c)
        else:
            d.appendleft(c)
if flip:
    d.reverse()
print(''.join(d))
