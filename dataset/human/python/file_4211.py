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

N = int(input())
cnt = 0
past = []
while True:
    n = prime_factorize(N)
    if not n:
        break
    m = set(n)
    nn = []
    for i in m:
        for j in range(1, n.count(i)+1):
            nn.append(pow(i, j))
    for i in nn:
        if not (i in past):
            N = int(N / i)
            past.append(i)
            cnt+=1
            break
    else:
        break
print(cnt)
