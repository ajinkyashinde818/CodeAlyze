def prime_factorize(num): # 整数に対し素因数分解
    prime_factor = {}
    i = 2
    while i ** 2 <= num:
        while num % i == 0:
            num //= i
            if i in prime_factor.keys():
                prime_factor[i] += 1
            else:
                prime_factor[i] = 1
        i += 1
    if num > 1:
        prime_factor[num] = 1
    return prime_factor

n = int(input())
data = prime_factorize(n)
ans = 0
for i in data:
    x = data[i]
    j = 1
    while j <= x:
        x -= j
        j += 1
        ans += 1
print(ans)
