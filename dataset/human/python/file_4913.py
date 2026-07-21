n = int(input())
lst1 = list(map(int,input().split()))
mod = 10**9+7
def pow(n, p):
    res = 1
    while p > 0:
        if p % 2 == 0:
            n = n ** 2 % mod
            p //= 2
        else:
            res = res * n % mod
            p -= 1
    return res % mod
fac = [1]

for i in range(n-1):
    fac.append(fac[-1]*(i+1)%mod)

f = 1
ans = 0
for i in range(n-1):
    ans += ((lst1[-1]-lst1[i])*fac[-1]*pow(i+1,mod-2))%mod
print(ans%mod)
