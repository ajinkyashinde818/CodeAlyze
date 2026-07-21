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

lst = Counter(a)
lst = list(lst.values())

ans = 0
for i in lst:
    cnt = 0
    while i - (cnt) > 0:
        cnt += 1
        i = i - (cnt)
        ans += 1
print(ans)
