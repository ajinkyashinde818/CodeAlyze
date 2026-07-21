from collections import deque

d = deque(input())

q = int(input())

headflag = 0

for i in range(q):
    s = input()
    if len(s) == 1:
        if headflag == 0:
            headflag = 1
        else:
            headflag = 0
    else:
        l = list(s)
        if headflag == 0:
            if l[2] == '1':
                d.appendleft(l[4])
            else:
                d.append(l[4])
        else:
            if l[2] == '2':
                d.appendleft(l[4])
            else:
                d.append(l[4])

result = ''.join(d)

if headflag == 0:
    print(result)
else:
    result = result[::-1]
    print(result)

print()
