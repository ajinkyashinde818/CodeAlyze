import sys
sys.setrecursionlimit(10000000)
MOD = 10 ** 9 + 7
INF = 10 ** 15

def main():
    N = int(input())
    X = list(map(int,input().split()))

    ans = 0
    fact = [1]
    for i in range(1,N):
        fact.append(fact[-1]*i%MOD)
    inv_fact = [1] * N
    inv_fact[-1] = pow(fact[N - 1],MOD - 2,MOD)
    for i in range(N - 1,0,-1):
        inv_fact[i - 1] = inv_fact[i]*i%MOD
    
    cum = 0
    for i in range(N - 1):
        cum += fact[N - 1] * inv_fact[i + 1] * fact[i] % MOD
        cum %= MOD
        ans += cum * (X[i + 1] - X[i])
        ans %= MOD
    print(ans)
if __name__ == '__main__':
    main()
