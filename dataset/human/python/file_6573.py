from collections import deque
s = deque(input())
q = int(input())

cnt = 0
for _ in range(q):
    i = input().split()
    t = int(i[0])

    if t == 1:
        cnt += 1
    else:
        f = int(i[1])
        c = i[2]
        if (cnt % 2 == 0 and f == 1) or (cnt % 2 == 1 and f == 2):
            s.appendleft(i[2])
        else:
            s.append(i[2])

if cnt % 2 == 1:
    s.reverse()
print(''.join(s))
