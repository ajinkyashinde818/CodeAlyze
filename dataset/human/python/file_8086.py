def g(s, k):
	if s < 0: return 0
	if s == 0: return 1
	if k <=s <= 2*k: 
		return k - (s - k) +1
		return k +1
	if s < k: return s + 1
	if s > 2*k: return 0 

def f(s,k):
	ans = 0
	for c in range(k+1): 
		ans += g(s - c,k)
	return ans
k,s = map(int, raw_input().split())
print f(s,k)
