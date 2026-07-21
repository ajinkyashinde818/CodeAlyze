from collections import deque

s = deque(input())
q = int(input())
qu = [[0] * 3] * q
count = 0

for i in range(q):
    qu[i] = input().split()

for i in range(q):
    if qu[i][0] == '1':
        count += 1
        continue

    else:
        if (count + int(qu[i][1])) % 2:
            s.appendleft(qu[i][2])
        else:
            s.append(qu[i][2])

if count % 2:
    s.reverse()

print(''.join(s))
