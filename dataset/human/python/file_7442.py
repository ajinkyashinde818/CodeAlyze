from collections import deque

s = input()
q = int(input())

dt = deque()
de = deque()

f1 = 1
f2 = 2

for _ in range(q):
    q = input().split()
    if int(q[0]) == 1:
        f1,f2 = f2,f1
    elif int(q[0]) == 2:
            if int(q[1]) == f1:
                dt.appendleft(q[2])
            elif int(q[1]) == f2:
                de.append(q[2])
                
st = "".join(dt)
se = "".join(de)
ans = st + s + se

if f1 == 1:
    print(ans)
else:
    ans = list(ans)
    ans.reverse()
    ans = "".join(ans)
    print(ans)
