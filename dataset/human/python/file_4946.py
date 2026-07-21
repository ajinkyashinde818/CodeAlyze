import math

n = int(input())
x = list(map(int, input().split()))

def c(n):
    if n == 1:
        return 1
    return c(n - 1) + 1 / n

mod = 10 ** 9 + 7
sum = 0
c = 0
for i in range(n - 1):
    c += pow(i + 1, mod - 2, mod)
    c %= mod
    sum += (x[i + 1] - x[i]) * c
    sum %= mod
ans = (sum * math.factorial(n - 1)) % mod
print(ans)
