from collections import Counter
N = int(input())
def prime_factorize(n):
    a = []
    while n % 2 == 0:
        a.append(2)
        n //= 2
    f = 3
    while f * f <= n:
        if n % f  == 0:
            a.append(f)
            n //= f
        else:
            f += 2
    if n != 1:
        a.append(n)
    return a
b = prime_factorize(N)
mycounter = Counter(b)
c = mycounter.most_common()
m = list(range(1,100))
count = 0
for i, j in c:
    sum = 0
    for k in m:
        sum += k
        if j < sum:
            count += k-1
            break
print(count)
