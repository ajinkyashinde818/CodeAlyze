from collections import deque
s = input()
Q = int(input())
s = deque([s])
rev = 1
for i in range(Q):
    tmp = list(input().split())
    if len(tmp)==1:
        rev *= -1
    else:
        f,c = tmp[1], tmp[2]
        if rev > 0:
            if f=='1':
                s.appendleft(c)
            else:
                s.append(c)
        else:
            if f=='1':
                s.append(c)
            else:
                s.appendleft(c)
s = ''.join(list(s))
print(s if rev > 0 else s[::-1])
