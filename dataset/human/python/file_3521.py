from collections import Counter
n = int(input())
a = []
while n % 2 == 0:
    a.append(2)
    n //= 2
f = 3
while f * f <= n:
    if n % f == 0:
        a.append(f)
        n //= f
    else:
        f += 2
if n != 1:
    a.append(n)

c = Counter(a)
ans = 0
loop = True
for i in c.values():
    x = 1
    while loop == True:
        if x * (x + 1) // 2 <= i < (x + 1) * (x + 2) // 2:
            break
        x += 1
    ans += x
print(ans)
