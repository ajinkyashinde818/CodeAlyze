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

a = [0]
for i in range(1, 10):
    a.append(a[i-1]+i)
a = a[1:]

n = int(input())
if n == 1:
    ans = 0
else:
    primes = factorization(n)
    ans = 0
    for prime in primes:
        t = prime[1]
        for i in range(10):
            if t < a[i]:
                ans += i
                break
print(ans)
