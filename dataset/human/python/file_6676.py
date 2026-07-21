from collections import deque
S = list(input())
Q = int(input())
perm = 0
d = deque(S)

for i in range(0, Q):
    l = input().split()
    if len(l) == 1:
        perm += 1
    else:
        if (int(l[1])+perm) % 2 == 0:
            d.append(l[2])
        else:
            d.appendleft(l[2])
 
S0 = list(d)
if perm % 2 != 0:
    S0.reverse()
ans = ""
for i in range(0, len(S0)):
    ans = ans + S0[i]
print(ans)
