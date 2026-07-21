def factorials_with_inv(k,mod):
    """
    0! ... k! とそれらのmod逆元を求めて返す
    """
    fac = [1]*(k+1)
    inv = [1]*(k+1)
    t = 1
    for i in range(1,k+1):
        t *= i
        t %= mod
        fac[i] = t

    t = pow(t,-1,mod)
    for i in reversed(range(1,k+1)):
        inv[i] = t
        t *= i
        t %= mod

    return fac, inv

def solve(X):
    MOD = 10**9+7
    N = len(X)-1
    DX = [b-a for a,b in zip(X,X[1:])]

    fac,inv = factorials_with_inv(N,MOD)
    res = 0
    s2 = 0
    s1 = 0
    s0 = 1

    P = fac[N]
    for k,d in enumerate(DX, start=2):
        x = s0-s1*(k-1)
        s2 = s1
        s1 = s0
        s0 = s0*k + x*(k+1) - s2
        x %= MOD
        s2 %= MOD
        s1 %= MOD
        s0 %= MOD
        res += x*P*inv[k-1]*d
        res %= MOD
    return res

if __name__ == '__main__':
    N = int(input())
    X = list(map(int,input().split()))
    print(solve(X))
