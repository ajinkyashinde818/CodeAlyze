def pfact(m):
	pf = {}
	for i in range(2,int(m**0.5)+1):
		while m%i == 0:
			pf[i] = pf.get(i,0) + 1
			m //= i
	if m>1 : pf[m]=1
	return pf

n = int(input())
pl = pfact(n).values()
ans = 0
for i in pl:
	k = i
	for j in range(1,41):
		k -= j
		if k < 0:
			break
		ans += 1
print(ans)
