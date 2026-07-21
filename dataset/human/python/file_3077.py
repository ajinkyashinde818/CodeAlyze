from collections import Counter

n = int(input())
a = list()
ans = 0
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
m = list(Counter(a).values())
for i in range(len(m)):
    j, k = 1, 1
    while m[i] >= j:
        k += 1
        j += k
        ans += 1
print(ans)
