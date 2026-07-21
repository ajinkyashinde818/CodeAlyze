from math import sqrt as r
from math import ceil as f
N = int(input())

dev2 = 0
N2 = N
while True:
    if N2 % 2 == 0:
        N2 /= 2
        dev2 += 1
    else:
        break

p = [2] * dev2

for c in range(3, f(r(N2)), 2):
    while True:
        if N2 % c == 0:
            N2 /= c
            p.append(int(c))
        else:
            break
if N2 != 1:
    p.append(int(N2))


pp = []
while True:
    if len(p) == 0:
        break
    pp.append(p.count(p[0]))
    del p[:pp[-1]]

#print(pp)
ans = 0

for c in pp:
    cou = 1
    while True:
        if cou + (cou + 1) > c:
            ans += cou
            break
        else:
            c -= cou
            cou += 1
print(ans)
