def b_fusing_slimes(MOD=10**9 + 7):
    from math import factorial
    N = int(input())
    X = [int(i) for i in input().split()]

    diff = [0] + [X[i + 1] - X[i] for i in range(N - 1)]
    cumsum = [0]
    for j in range(1, N):
        cumsum.append((cumsum[-1] + pow(j, MOD - 2, MOD)) % MOD)

    ans = sum([(diff[i] * cumsum[i]) % MOD for i in range(1, N)]) % MOD
    return (ans * factorial(N - 1)) % MOD

print(b_fusing_slimes())
