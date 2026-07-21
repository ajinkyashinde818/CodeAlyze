def i():
	return int(input())
def i2():
	return map(int,input().split())
def s():
	return str(input())
def l():
	return list(input())
def intl():
	return list(int(k) for k in input().split())

n = i()
a = intl()
b = intl()
c = intl()

ans = 0
for i in range(n):
	ans += b[ a[i]-1 ]
	if a[i] - a[i-1] == 1 and i >= 1:
		ans += c[ a[i-1]-1 ]
print(ans)
