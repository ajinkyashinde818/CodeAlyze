def prime_factorize(N): #素因数分解
    exponent = 0
    while N%2 == 0:
        exponent += 1
        N //= 2
    if exponent: factorization = [[2,exponent]]
    else: factorization = []
    i=1
    while i*i <=N:
        i += 2
        if N%i: continue
        exponent = 0
        while N%i == 0:
            exponent += 1
            N //= i
        factorization.append([i,exponent])
    if N!= 1: factorization.append([N,1])
    assert N != 0, "zero"
    return factorization

N = int(input())

pr = prime_factorize(N)


l = len(pr)
s = sum((i for _,i in pr))
ans = 0

ans = 0
for p,e in pr:
    tmp = 1
    ttmp = e
    res = 0
    for i in range(100000):
        if ttmp - tmp < 0:
            break
        res += 1
        ttmp -= tmp
        tmp += 1
    ans += res

print(ans)
