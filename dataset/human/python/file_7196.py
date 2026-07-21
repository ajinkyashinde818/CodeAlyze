from collections import deque
s = deque(list(input()))
q = int(input())
t1 = 1
for i in range(q):
    t = input()
    if t == '1':
        t1 *= -1
    else:
        if t1 == 1:
            if t[2] == '1':
                s.appendleft(t[4])
            else:
                s.append(t[4])
        else:
            if t[2] == '2':
                s.appendleft(t[4])
            else:
                 s.append(t[4])

ans = ''
if t1 == -1:
    ans = ''.join(reversed(s))
else:
    ans = ''.join(s)

print(ans)
