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
def counter(array):
    from collections import Counter
    return list(Counter(array).most_common())
c = counter(prime_factorize(int(input())))
table = [(i + 1)*i//2 for i in range(100)]


from bisect import bisect_right
ans = 0
for x in c:
    ans += bisect_right(table,x[1]) - 1
print(ans)
