n = int(input())
cnt = 0

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

a = factorization(n)
c = 0
for i in a:
	k = 1
	x = i[1]
	while x-k >= 0:
		x -= k
		c += 1
		k += 1
if n == 1:
	print (0)
else:
	print (c)
