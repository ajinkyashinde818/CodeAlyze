n = int(input())

def factorize(x):
    res = {}
    p = 2
    while p * p <= x:
        if x % p != 0: 
            p += 1
            continue
        cnt = 0
        while x % p == 0:
            x //= p
            cnt += 1
        res[p] = cnt
        p += 1
    if x != 1:
        res[x] = 1
    return res

f = factorize(n)

ans = 0
for pe in f.items():
    for e in range(1, pe[1] + 1):
        z = pe[0] ** e
        if n % z == 0:
            n //= z
            ans += 1

print(ans)
