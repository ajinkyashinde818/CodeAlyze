MOD = 10**9+7

def inv_mod(n,mod):
    inv_mod = [0]*(n+1)
    inv_mod[1] = 1
    for i in range(2,n+1):
        inv_mod[i] = mod - inv_mod[mod%i] * (mod//i ) % mod
    
    return inv_mod

n = int(input())
x = list(map(int,input().split()))

x_dif = [x2-x1 for x1,x2 in zip(x,x[1:])]

fac = 1
for i in range(1,n):
    fac *= i
    fac %= MOD

inv = inv_mod(n,MOD) 
    
ans = 0
count = 0
for i,dist in enumerate(x_dif,1):
    count += (fac * inv[i]) %MOD
    count %= MOD
    
    ans += (dist * count)%MOD
    ans %= MOD

print(ans)
