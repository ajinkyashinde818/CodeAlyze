from math import factorial

N = int(input())
x = list(map(int, input().split()))
mod = 10**9 + 7
x_dis = [x[i+1] - x[i] for i in range(N-1)]
ans = 0
m = N-1
fac = factorial(m) % mod
tmp = fac
for i in range(m):
    ans += x_dis[i] * tmp
    ans %= mod
    tmp += (fac*pow((i+2),(mod-2), mod))%mod
print(ans)
