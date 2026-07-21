from collections import Counter
n = int(input())
def prime_factorize(n):
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
    return a
l = prime_factorize(n)
c = Counter(l)
l3 = []
for i in c.most_common():
    l3.append(i[1])
l2 = [i * (i + 1) // 2 for i in range(1, 10)]
ans = 0
for i in l3:
    for j in range(len(l2)):
        if l2[j] > i:
            ans += j
            break
print(ans)
