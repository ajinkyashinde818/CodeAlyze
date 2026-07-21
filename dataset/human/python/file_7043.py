from collections import deque

S = input()
Q = int(input())

D1 = deque()
D2 = deque()

rev = False

for i in range(Q):
    q = input().split()
    if int(q[0]) == 1:
        if rev == True:
            rev = False
        else:
            rev = True
    else:
        f = int(q[1])
        c = q[2]
        if f == 1:
            if not rev:
                D1.appendleft(c)
            else:
                D2.append(c)
        else:
            if not rev:
                D2.append(c)
            else:
                D1.appendleft(c)


ans = ''.join(D1)+S+''.join(D2)

if not rev:
    print(ans)

else:
    print(ans[::-1])
