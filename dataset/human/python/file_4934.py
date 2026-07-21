MOD = 10**9 + 7
N = int(input())
X = list(map(int, input().split()))
D = [dj - di for di, dj in zip(X, X[1:])]

def power(n, r, mod=10**9+7):
    if r == 0: return 1
    if r%2 == 0:
        return power(n*n % mod, r//2, mod) % mod
    if r%2 == 1:
        return n * power(n, r-1, mod) % mod

def framod(n, a=1, mod=10**9+7):
    for i in range(1,n+1):
        a = a * i % mod
    return a

count_d = []
frac_Nm1 = framod(N-1)
for i in range(1, N):
  count_d.append(frac_Nm1 * power(i, MOD-2) % MOD)

for i in range(1, N-1):
  count_d[i] += count_d[i-1]


ans = sum([d*c % MOD for d, c in zip(D, count_d)]) % MOD
print(ans)
