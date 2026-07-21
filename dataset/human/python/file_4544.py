def factorization(n):
    arr = []
    temp = n
    for i in range(2, int(-(-n**0.5//1))+1):
        if temp % i == 0:
            cnt = 0
            while temp % i == 0:
                cnt += 1
                temp //= i
            arr.append([i, cnt])
    if temp != 1:
        arr.append([temp, 1])
    if arr == []:
        arr.append([n, 1])
    return arr


N = int(input())
primes = factorization(N)
ans = 0
for p in primes:
    num = p[1]
    for i in range(1, N):
        if num >= i:
            num -= i
            ans += 1
        else:
            break
print(ans)
