N = int(input())

def factorization(num):
    res = []
    n = num
    div_max = int(num ** 0.5)
    for i in range(2, div_max+1):
        if n % i == 0:
            count = 0
            while n % i == 0:
                count += 1
                n //= i
            res.append([i, count])

    if n != 1:
        res.append([n, 1])

    if len(res) == 0:
        res.append([num, 1])

    return res

res = factorization(N)

ans = 0
for i in range(len(res)):

    p, n = res[i]
    if p != 1:
        j = 1
        while n - j >= 0:
            ans += 1
            n -= j
            j += 1

print(ans)
