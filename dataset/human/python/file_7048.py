from collections import deque
s = deque(list(input()))
q = int(input())
flg = True
for _ in range(q):
    try:
        t,f,c = input().split()
        if flg:
            if f == "1":
                s.appendleft(c)
            else:
                s.append(c)
        else:
            if f == "1":
                s.append(c)
            else:
                s.appendleft(c)
    except ValueError:
        if flg:
            flg = False
        else:
            flg = True
if flg:
    print(''.join(s))
else:
    s = list(reversed(s))
    print(''.join(s))
