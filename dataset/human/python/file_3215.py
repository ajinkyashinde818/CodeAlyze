def factorization(n):
    arr = []
    temp = n
    for i in range(2, int(-(-n**0.5//1))+1):
        if temp%i==0:
            cnt=0
            while temp%i==0:
                cnt+=1
                temp //= i
            arr.append([i, cnt])

    if temp!=1:
        arr.append([temp, 1])

    if arr==[]:
        arr.append([n, 1])

    return arr

N = int(input())

if N == 1:
    print(0)
    exit()

primes = factorization(N)

ans = 0
for _, cnt in primes:
    n = 0
    while n * (n + 1) // 2 <= cnt:
        n += 1
    ans += n - 1

print(ans)
