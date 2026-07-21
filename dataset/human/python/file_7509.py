from collections import deque
s = input()
q = int(input())
flag = True
d = deque(s)
for i in range(q):
    inp = input()
    if inp == '1':
        flag = not flag

    else:
        _, f, c = map(str, inp.split())
        if f == '1':
            if flag:
                d.appendleft(c)
            else:
                d.append(c)
        else:
            if flag:
                d.append(c)
            else:
                d.appendleft(c)

if flag:
    while(d):
        t = d.popleft()
        print(t, end='')
else:
    while(d):
        t = d.pop()
        print(t, end='')
