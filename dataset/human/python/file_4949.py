import math
def powmod(x, n,mod):
  if n == 0:
   return 1
  K = 1
  while n > 1:
   if n % 2 != 0:
    K = K * x%mod
    x = x ** 2%mod
    n = (n - 1) // 2
   else:
    x = x ** 2%mod
    n = n // 2%mod

  return K * x # 指数を割り続け n が 1 に至ったら終了
def cmbmod(n, r,mod):
    if n - r < r: r = n - r
    if r == 0: return 1
    if r == 1: return n

    numerator = [n - r + k + 1 for k in range(r)]
    denominator = [k + 1 for k in range(r)]

    for p in range(2,r+1):
        pivot = denominator[p - 1]
        if pivot > 1:
            offset = (n - r) % p
            for k in range(p-1,r,p):
                numerator[k - offset] /= pivot
                denominator[k] /= pivot

    result = 1
    for k in range(r):
        if numerator[k] > 1:
            result = result*int(numerator[k])%mod
    return result
N=int(input())
X = list(map(int,input().split()))
T=0
mod=10**9+7
pmod=0
A=math.factorial(N-1)%mod
for i in range(1,N):
 pmod+=powmod(i, mod - 2, mod)
 T+=(X[i]-X[i-1])*pmod
 T%=mod
print((A*T)%mod)
