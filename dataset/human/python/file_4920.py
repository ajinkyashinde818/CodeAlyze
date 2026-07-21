import math

n = int(input())
x = [0] + list(map(int, input().split()))
mod = 10**9 + 7

s = [pow(i, mod-2, mod) for i in range(0,n+1)]
for i in range(n):
    s[i+1] = (s[i+1] + s[i]) % mod

ans = 0
for i in range(1,n):
    ans += ((x[i+1] - x[i]) * s[i]) % mod
ans = int(ans * math.factorial(n-1)) % mod
print(ans)
