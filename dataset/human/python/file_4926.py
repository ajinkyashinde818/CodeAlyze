import math
n=int(input())
a=list(map(int,input().split()))
ans=math.factorial(n-1)%(10**9+7)

def modinv(a, mod=10**9+7):
    return pow(a, mod-2, mod)

c=0
for i in range(1,n):
    c+=(a[-1]-a[i-1])*modinv(i, mod=10**9+7)
print(ans*c%(10**9+7))
