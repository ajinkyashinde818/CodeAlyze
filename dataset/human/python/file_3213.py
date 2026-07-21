import math
def eratos(n):
    isprime = [True for i in range(n+1)]
    isprime[0] = False
    isprime[1] = False
    for i in range(2, int(math.sqrt(n))+13):
        if isprime[i]:
            j = i + i
        while j <= n:
            isprime[j] = False
            j = j + i
    return isprime
N = int(input())
ans = 0
is_prime = eratos(10**6+13)
for i in range(2, 10**6+14):
    if not is_prime[i]:
        continue
    x = i
    while N % x == 0:
        ans += 1
        N //= x
        x *= i
        # print(N)
if ans == 0 and N != 1:
    ans += 1
elif N > 10**6:
    ans += 1
print(ans)
