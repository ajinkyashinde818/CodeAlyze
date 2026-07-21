from bisect import bisect_left

def prime_factorize(n):
    res = []
    for i in range(2, int(n**(1/2))+1):
        if n % i != 0: continue
        num = 0
        while n % i == 0:
            num += 1
            n /= i
        res.append((i, num))
    if n != 1:
        res.append((n, 1))
    
    return res

n = int(input())

prime = prime_factorize(n)

c = [1, 3, 6, 10, 15, 21, 28, 36, 45, 55]

ans = 0
for k, v in prime:
    i = bisect_left(c, v)
    if c[i] == v: i += 1
    ans += i

print(ans)
