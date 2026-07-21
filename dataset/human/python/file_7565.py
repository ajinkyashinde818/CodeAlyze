from collections import deque

S = input()
Q = int(input())

d = deque(S)
flg = True #Trueが前から,
for i in range(Q):
    t, *a = input().split()
    if t == "1":
        flg = not flg
    else:
        if (flg and a[0]=="1") or ((not flg) and a[0]=="2"):
            d.appendleft(a[1])
        else:
            d.append(a[1])
d = list(d)
if flg:
    print(''.join(d))
else:
    print(''.join(d[::-1]))
