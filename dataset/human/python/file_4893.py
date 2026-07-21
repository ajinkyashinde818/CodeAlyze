import sys
input = sys.stdin.buffer.readline
import copy

def main():
    N = int(input())
    x = list(map(int,input().split()))
    MOD = 10**9+7
    fac = [0 for _ in range(N+1)]
    fac[0],fac[1] = 1,1
    inv = copy.deepcopy(fac)
    invfac = copy.deepcopy(fac)
    
    for i in range(2,N+1):
        fac[i] = (fac[i-1]*i)%MOD
        inv[i] = MOD-(MOD//i)*inv[MOD%i]%MOD
        invfac[i] = (invfac[i-1]*inv[i])%MOD

    cum = [0]
    for i in range(N):
        cum.append(cum[-1]+inv[i+1])

    ans = 0
    for i in range(N-1):
        d = x[i+1]-x[i]
        ans += (d*cum[i+1])%MOD
        
    print((ans*fac[N-1])%MOD)

if __name__ == "__main__":
    main()
