import sys,collections as cl,bisect as bs
Max = sys.maxsize
def l():
	return list(map(int,input().split()))
def m():
	return map(int,input().split())
def s(x):
	a = []
	aa = x[i]
	su = 1
	for i in range(len(x)-1):
		if aa == x[i+1]:
			a.append([aa,su])
			aa = x[i+1]
			su = 1
		else:
			su += 1
	a.append([aa,su])
	return a
def jo(x):
	return " ".join(map(str,x))


r,b,g,n = m()
co = 0
for i in range(n//r+1):
	for j in range((n-r*i)//b+1):
		if ((n - (i*r + j * b)) % g) == 0:
			co += 1
print(co)
