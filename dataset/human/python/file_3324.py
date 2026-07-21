N = int(input())
def factorization(n):
    D = {}
    a = n
    p = 2
    while a != 1:
        cnt = 0
        while a % p == 0:
            cnt += 1
            a //= p
        if cnt != 0:
            D[p] = cnt
        p += 1
        if p * p > n and a != 1:
            D[a] = 1
            break
    return D
f = factorization(N)
X = [0 for _ in range(101)]
for i in range(101):
    X[i] = i*(i+1)//2
p = 0
for i in f:
    x = f[i]
    for j in range(100):
        if X[j] <= x < X[j+1]:
            p += j
            f[i] -= X[j]
            break
print(p)
