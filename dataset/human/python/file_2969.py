from collections import defaultdict

D = defaultdict(int)

N = int(input())

x = N
y = 2
while y*y <= x:
    while x % y == 0:
        D[y] += 1
        x //= y
    y += 1
if x > 1:
    D[x] += 1

res = 0
for k, v in D.items():
    i = 1
    c = 0
    v -= 1
    while v >= 0:
        c += 1
        i += 1
        v -= i
    res += c

print(res)
