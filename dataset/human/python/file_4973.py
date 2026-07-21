MOD = 10**9+7
N = int(input())
x = list(map(int, input().split()))

def mod_pow(x, n, mod):
	res = 1
	while n > 0 : 
		if n&1 : 
			res = res * x % mod
		x = x * x % mod
		n >>= 1
	return res

prob = []
a = 0
for i in range(1, N):
	a += mod_pow(i, MOD-2, MOD)
	a %= MOD
	prob.append(a)
ans = 0
for i in range(1, N):
	ans += prob[i-1] * (x[i] - x[i-1])
	ans %= MOD
for i in range(1, N):
	ans = ans * i % MOD
print(ans)
