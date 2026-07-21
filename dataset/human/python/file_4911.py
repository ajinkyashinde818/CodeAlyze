import sys
input = lambda: sys.stdin.readline().rstrip()
inpl = lambda: list(map(int,input().split()))
def inv_mod(a, p=10**9+7):
    p = abs(p)
    a %= p
    stack = []
    p0 = p
    while a > 1:
        d, a, p = p//a, p%a, a
        stack.append(d)
    x, y = 1, 0
    while stack:
        d = stack.pop()
        x, y = y-d*x, x
    return x % p0
MOD = 10**9 + 7

N = int(input())
x = inpl()
d = [x[i+1]-x[i] for i in range(N-1)]

fac = 1
for i in range(2,N):
    fac = fac * i % MOD
inv = [ inv_mod(i,MOD) for i in range(1,N)]

ans = 0
s = 0
for i in range(N-1):
    s += inv[i]
    ans += d[i]*s
    ans %= MOD
ans = ans * fac % MOD
print(ans)
