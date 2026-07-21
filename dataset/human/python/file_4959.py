import math

n = int(input())
x = list(map(int, input().split()))
ans = 0
mod = 10 ** 9 + 7
f = 1
for i in range(1,n):
  f *= i
  f %= mod

for i in range(n-1):
    ans+=(x[n-1]-x[i])*pow(i+1,mod-2,mod)

ans*=f
ans%=mod


print(ans)
