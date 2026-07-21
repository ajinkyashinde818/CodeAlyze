import sys
input = sys.stdin.readline

MAX = 2*10**5+100
MOD = 10**9+7
fact = [0]*MAX #fact[i]: i!
inv = [0]*MAX #inv[i]: iの逆元
finv = [0]*MAX #finv[i]: i!の逆元
fact[0] = 1
fact[1] = 1
finv[0] = 1
finv[1] = 1
inv[1] = 1
    
for i in range(2, MAX):
    fact[i] = fact[i-1]*i%MOD
    inv[i] = MOD-inv[MOD%i]*(MOD//i)%MOD
    finv[i] = finv[i-1]*inv[i]%MOD

def C(n, r):
    if n<r:
        return 0
    if n<0 or r<0:
        return 0
    return fact[n]*(finv[r]*finv[n-r]%MOD)%MOD
    
N = int(input())
x = list(map(int, input().split()))
ans = 0
acc = [0]

for i in range(N-1):
    acc.append((acc[-1]+C(N-1, i+1)*fact[i]*fact[N-1-(i+1)])%MOD)

for i in range(N-1):
    d = x[i+1]-x[i]
    ans += d*acc[i+1]
    ans %= MOD
    """
    for j in range(i+1):
        ans += d*C(N-1, j+1)*fact[j]*fact[N-1-(j+1)]
        ans %= MOD
    """
print(ans)
