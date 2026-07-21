import random,math

def MillerRabinPrimalityTest(n):
	if n == 2:
		return True;
	if n == 1 or n & 1 == 0:
		return False
	d = (n - 1) >> 1
	while d & 1 == 0:
		d >>= 1
	for k in range(int(math.log(n, 4))):
		a = random.randint(1, n - 1)
		t = d
		y = pow(a, t, n)
		while t != n - 1 and y != 1 and y != n - 1:
			y = (y * y) % n
			t <<= 1
		if y != n - 1 and t & 1 == 0:
			return False
	return True
def nextp(prevp):
	if(prevp<=3):
		return 2
	prevp-=1
	while(True):
		if(MillerRabinPrimalityTest(prevp)):
			break
		prevp-=1
	return prevp
def factorization(n):
	arr = []
	temp = n
	for i in range(2, int(-(-n**0.5//1))+1):
		if temp%i==0:
			cnt=0
			while temp%i==0:
				cnt+=1
				temp //= i
			arr.append([i, cnt])
	if temp!=1:
		arr.append([temp, 1])
	if arr==[]:
		arr.append([n, 1])
	return arr

N = int(input())
if(N==1):
	print(0)
else:
	ans = 0;
	facts = factorization(N)
	for fact in facts:
		used = 0
		left = fact[1]
		while True:
			used+=1
			ans+=1
			left-=used
			if left<=used:
				break
	print(ans);
