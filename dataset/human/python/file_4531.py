from collections import Counter

n = int(input())

ps = []
while n % 2 == 0:
    ps.append(2)
    n //= 2
f = 3
while f * f <= n:
    if n % f == 0:
        ps.append(f)
        n //= f
    else:
        f += 2
if n != 1:
    ps.append(n)

ans = 0
for p, x in Counter(ps).items():
    i = 1
    j = 1
    if x != 1:
        while i <= x:
            j += 1
            i += j
        ans += j-1
    else:
        ans += 1

print(ans)
