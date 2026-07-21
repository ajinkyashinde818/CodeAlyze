import math
import sys 
input = sys.stdin.readline

N = int(input())
x = list(map(int,input().split()))
mod = 10**9+7

d = [0]*(N-1)

for i in range(N-1):
    d[i] = x[i+1]-x[i]
    d[i] %= mod


kaijou = 1
for i in range(1,N):
    i %= mod
    kaijou *= i
    kaijou %= mod #これをしないとkaijouが発散


ans=0
x=0

def pow_a(a,n): #(modを取るように改良)
    if n==0:
        return 1
    
    K = 1
    while n>1:
        if n%2 != 0:
            K *= a
            K %= mod
        a *= a
        a %= mod
        n //= 2

    return (K*a)%mod

for i in range(N-1):
    y = pow_a(i+1,mod-2) #i+1の逆元
    x += kaijou*y
    ans += d[i]*x
    ans %= mod

print(ans)
