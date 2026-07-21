from collections import deque
S = input()
Q = int(input())
k = 1
d = deque(S)
for _ in range(Q):
    query = input()
    if query.startswith('1'):
        k *= -1
    elif query.startswith('2'):
        t, f, c = query.split()
        if f == '1':
            if k > 0:
                d.appendleft(c)                
            else:
                d.append(c)
        elif f == '2':
            if k > 0:
                d.append(c)
            else:
                d.appendleft(c)
d = list(d)
if k > 0:
    print(''.join(d))
else:
    print(''.join(d[::-1]))
