from collections import deque

s = input()
d = deque(s)
n = int(input())
flag = 0
for _ in range(n):
    q = input().split()
    if (len(q)==1):
        if(flag == 0):
            flag = 1
        else:
            flag = 0
    else:
        a = int(q[1])
        b = q[2]
        if (a == 1):
            if flag==0:
                d.appendleft(b)
            else:
                d.append(b)
        else:
            if flag==0:
                d.append(b)
            else:
                d.appendleft(b)

if flag==1:
    d.reverse()
ans = list(d)
xxx = "".join(ans)
print(xxx)
