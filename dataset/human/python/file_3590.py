def factorization(n):
    from collections import Counter
    arr = Counter()
    temp = n
    for i in range(2, int(-(-n**0.5 // 1)) + 1):
        if temp % i == 0:
            cnt = 0
            while temp % i == 0:
                cnt += 1
                temp //= i
            arr[i] = cnt

    if temp != 1:
        arr[temp] = 1

    if len(arr.keys()) == 0 and n != 1:
        arr[n] = 1

    return arr


N = int(input())

primes = factorization(N)

cnt = 0
for p, n in primes.items():
    k = 1
    while n >= k:
        cnt += 1
        n -= k
        k += 1
print(cnt)
