n = int(input())
if n == 1:
    print(0)
    exit()
def prime_factorize(n):
    a = []
    while n % 2 == 0:
        a.append(2)
        n //= 2
    f = 3
    while f**2 <= n:
        if n % f == 0:
            a.append(f)
            n //= f
        else:
            f += 2
    if n != 1:
        a.append(n)
    return a
b = []
d = prime_factorize(n)
c = len(d)
count = 1
for i in range(1,c):
    if d[i] != d[i-1]:
        b.append(count)
        count = 1
    else:
        count+=1
b.append(count)
ans = 0
for i in b:
    j = 1
    count2 = 0
    while count2 <= i:
        count2 += j
        j += 1
    ans += (j - 2)
print(ans)
