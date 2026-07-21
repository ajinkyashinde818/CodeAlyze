mod = 998244353
k, n = map(int, input().split())


def inv(a,mod):
    r = [1,0,a]
    w = [0,1,mod]
    while w[2]!=1:
        q = r[2]//w[2]
        r_new = [r[0]-q*w[0],r[1]-q*w[1],r[2]-q*w[2]]
        r = w
        w = r_new
    x,y = w[0],w[1]    # a*x+y*mod = 1
    return (mod+x%mod)%mod

max_num = 2*10**5+1
fact = [0 for _ in range(max_num)]
ifact = [0 for _ in range(max_num)]

fact[0] = fact[1] = 1
ifact[0] = ifact[1] = 1

for i in range(2,max_num):
    fact[i] = fact[i-1] * i % mod

ifact[max_num-1] = inv(fact[max_num-1],mod)

for i in range(2,max_num):
    ifact[max_num-i] = (ifact[max_num-i+1] * (max_num-i+1)) %mod

def comb(x,y):
    if x < 0 or y < 0 or x < y:
        return 0
    else:
        return fact[x] * ifact[y] * ifact[x-y] % mod


if k == 1:
    print(0)
    exit()
elif k == 2:
    print(2)
    print(2)
    print(2)
    exit()

ansl = [0]*(2*k-1)

for ii in range(2, 2*k+1):
    ans = 0
    j = max(1,ii-k)

    if i % 2 == 0:
        pair = ii//2 - j
        mid = 1
    else:
        pair = (ii+1)//2 - j
        mid = 0

    if pair == 0:
        ans += comb(n-1+k-2, k-2) + comb(n+k-2, k-2)
        ans %= mod
    else:
        if mid == 0:
            for i in range(pair+1):
                if k-2*pair+i == 0:
                    continue
                ans += comb(pair, i) * 2**i * comb(n-i + k-2*pair+i-1, k-2*pair+i-1)
                ans %= mod
        else:
            for i in range(pair+1):
                if k-2*pair-mid+i == 0:
                    continue
                ans += comb(pair, i) * 2**i * comb(n-i-1+k-2*pair-mid+i-1,k-2*pair-mid+i-1)
                ans += comb(pair, i) * 2**i * comb(n-i+k-2*pair-mid+i-1,k-2*pair-mid+i-1)
                ans %= mod
    ansl[ii-2] = ans
    if ii == k+1:
        break


for i in range(k-1):
    print(ansl[i])

print(ansl[k-1])

for i in range(k+1,2*k):
    print(ansl[2*k-1-i])
