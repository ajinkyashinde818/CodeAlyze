n = int(input())
b = n
def pf(n):
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
l = list(set(pf(n)))
cnt = 0
for i in l:
    n = b
    t = 1
    j = i
    while i <= n:
        if n % i == 0:
            cnt += 1
            n = n // i
        i *= j
print(cnt)
