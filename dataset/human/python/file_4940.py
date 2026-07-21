N = int(input())
X = list(map(int,input().split()))
import math
ans = 0
mod = 10**9+7
a = 0
ans = 0
for i in range(N-1):
  a += pow(i+1,mod-2,mod)
  ans += ((X[i+1]-X[i])%mod)*(a%mod)
  ans %= mod
  
ans *= math.factorial(N-1)%mod

print(ans%mod)
