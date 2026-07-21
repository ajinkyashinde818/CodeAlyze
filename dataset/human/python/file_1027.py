from math import factorial
n = int(input())
s = input()
mod = 10**9+7
t = ""
for i,c in enumerate(s):
	if i%2:
		t += "L" if c=="W" else "R"
	else:
		t += "R" if c=="W" else "L"
if t.count("L")!=t.count("R"):
	print(0)
else:
	ans = 1
	Lcnt = 0
	for i in t:
		if i=="L":
			Lcnt += 1
		else:
			ans *= Lcnt
			Lcnt -= 1
		ans %= mod
	print(ans*factorial(n)%mod)
