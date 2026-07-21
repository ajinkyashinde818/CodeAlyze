import math

N = int(input())

x = N
n = math.floor(math.sqrt(N))
p = {}
i = 2

while i <= n:
    while x % i == 0:
        p.setdefault(i, 0)
        p[i] += 1
        x //= i
    i += 1

if x != 1:
    p.setdefault(x, 1)

ans = 0

for v in p.values():
    i = 1
    while v - i >= 0:
        v -= i
        ans += 1
        i += 1

print(ans)
