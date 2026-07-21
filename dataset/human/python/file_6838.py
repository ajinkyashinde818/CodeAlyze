from collections import deque

s = input()
s = deque(s)
q = int(input())
rev = 1

for _ in range(q):
    input_ = input()
    if input_ == '1':
        rev *= -1
        continue
    _, f, c = input_.split()
    if rev == 1:
        if f == '1':
            s.appendleft(c)
        else:
            s.append(c)
    else:
        if f == '1':
            s.append(c)
        else:
            s.appendleft(c)
ans = list(s)
if rev == -1:
    ans = ans[::-1]

print(''.join(ans))
