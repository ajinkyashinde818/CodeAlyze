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


n = int(input())
cnt = 0
lis = list(set(prime_factorize(n)))
for i in range(len(lis)):
    for j in range(1, 10**9):
        if n % lis[i]**j == 0:
            n /= lis[i]**j
            cnt+=1
        else:
            break
print(cnt)
