N = int(input())
x = list(map(int,input().split()))
d = [x[i+1]-x[i] for i in range(N-1)]

MOD = 10**9 + 7
def inv(a):
	b = MOD
	u = 1
	v = 0
	while b > 0:
		t = a // b
		a -= t*b
		a,b = b,a
		u -= t*v
		u,v = v,u
	u %= MOD
	return u

facts = [1]
for i in range(1, N+1):
	facts.append((facts[-1] * i) % MOD)

ans = 0
bunshi = 1
bunbo = 1
for i in range(1, N):
	keisu = (facts[N-1] * bunshi * inv(bunbo)) % MOD
	ans = (ans + keisu * d[i-1]) % MOD
	bunshi = (bunshi * (i+1) + bunbo) % MOD
	bunbo = (bunbo * (i+1)) % MOD
print(ans)
