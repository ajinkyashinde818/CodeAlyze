mod = 10**9+7

def frac(limit):
    frac = [1]*limit
    for i in range(2,limit):
        frac[i] = i * frac[i-1]%mod
    fraci = [None]*limit
    fraci[-1] = pow(frac[-1], mod -2, mod)
    for i in range(-2, -limit-1, -1):
        fraci[i] = fraci[i+1] * (limit + i + 1) % mod
    return frac, fraci
frac, fraci = frac(200000)

def count(S):
    res = 1
    cnt = 0
    for s in S:
        if s:
            cnt += 1
        else:
            res = (res*cnt)%mod
            cnt -= 1
        if cnt < 0:
            return 0
    return res
N = int(input())
S = [1 if s == 'B' else 0 for s in input().strip()]
L = 2*N
S = [(S[i] + i)%2 for i in range(L)]
if sum(S) != N:
    print(0)
else:
    print(count(S)*frac[N]%mod)
