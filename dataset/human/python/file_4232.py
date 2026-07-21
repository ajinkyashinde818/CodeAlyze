N = int(input())

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
    return list(set(a))

a = prime_factorize(N)
count, j = 0, 0
for i in a:
    j = 0
    while N % pow(i, j+1) == 0:
        N /= pow(i, j+1)
        j += 1
    count += j
        
print(count)
