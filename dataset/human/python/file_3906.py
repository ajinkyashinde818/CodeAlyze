import math
Max = 1000001
prime = Max*[1]
def sieve():
	prime[0] = 0
	prime[1] = 0
	for i in range(2,Max):
		if prime[i]==1:				
			j = 2*i
			while j < Max:
				prime[j] = 0
				j += i

def Howmany(x):
	res = 1
	while x>=res:
		x -= res
		res += 1
	return res-1

N = int(input())
sieve()
ans = 0
R = int(math.sqrt(N))
for i in range(2, R):
	if prime[i]==1 and N%i==0:
		cnt = 0
		while N%i==0:
			N //= i
			cnt+=1
		ans += Howmany(cnt)

if N!=1:
	ans += 1
print(ans)
