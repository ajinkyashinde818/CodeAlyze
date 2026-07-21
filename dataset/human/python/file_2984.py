from math import ceil
n = int(input())
pf = []
t = n
if n == 1:
    print(0)
    exit()
for i in range(2, ceil(n ** 0.5) + 1):
    c = 0
    while t % i == 0:
        c += 1
        t //= i
    if c > 0: pf.append(c)
if t != 1: pf.append(1)

ans = 0
for i in pf:
    tmp = i
    j = 1
    while j <= tmp:
        tmp -= j
        ans += 1
        j += 1
print(ans)
