def make_prime_factors_compress(n: int) -> list:
    """自然数nの素因数を列挙した圧縮済みリストを出力する
    計算量：O(sqrt(N))
    入出力例：156 -> [(2, 2), (3, 1), (13, 1)]
    """
    prime_factors = []
    for k in range(2, int(n ** 0.5) + 1):
        cnt = 0
        while n % k == 0:
            cnt += 1
            n = n // k
        if cnt != 0:
            prime_factors.append((k, cnt))
    if n != 1:
        prime_factors.append((n, 1))
    return prime_factors


n = int(input())
primes = make_prime_factors_compress(n)
ans = 0
for _, cnt in primes:
     for i in range(10000):
         if i * (i + 1) // 2 > cnt:
            ans += i - 1
            break
print(ans)
