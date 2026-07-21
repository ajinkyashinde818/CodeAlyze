mod = 10 ** 9 + 7

N = int(input())
X = list(map(int,input().split()))

def factorial(n, mod):
    fact = 1
    for integer in range(1, n + 1):
        fact *= integer
        fact %= mod
    return fact

fact = factorial(N-1, mod)
ans = 0
cnt = 0
for i in range(1, N):
    cnt += pow(i, mod - 2, mod)
    ans += (X[i] - X[i-1]) * cnt

ans *= fact
ans %= mod

print(ans)
