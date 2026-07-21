from math import factorial
 
N = int(input())
lst = [int(x) for x in input().split(" ")]
mod = 10**9 + 7
dists = [lst[i+1] - lst[i] for i in range(N-1)]
ans = 0
m = N - 1
fac = factorial(m) % mod
tmp = fac

for i in range(m):
    ans += dists[i] * tmp
    ans %= mod
    tmp += fac*pow((i+2), (mod-2), mod) % mod
    
print(ans)
