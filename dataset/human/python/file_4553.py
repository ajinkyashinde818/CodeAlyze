import math
n = int(input())

def pF(n):
	fList = []
	while (n%2 == 0):
		fList.append(2)
		n = n//2

	x = int(math.sqrt(n))
	for i in range(3,x+1,2):
		while (n%i == 0):
			fList.append(i)
			n = n//i

	if n>2:
		fList.append(n)

	return set(fList)

pSet = pF(n)

ans = 0

for p in pSet:
	i = 1
	while (n%(p**i)==0):
		n = n//(p**i)
		ans += 1
		i += 1

print(ans)
