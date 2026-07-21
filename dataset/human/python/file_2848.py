import math
import bisect

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

n = int(input())
if n == 1:
	print(0)
else:
	arr = factorization(n)
	max_count = max([x[1] for x in arr])
	binomial_count = [1]
	k = 1
	i = 1
	while True:
		i += 1
		k += i
		binomial_count.append(k)
		if k > max_count:
			break

	ans = 0
	for x in arr:
		ans += bisect.bisect_right(binomial_count, x[1])
	# print(arr)
	# print(binomial_count)
	print(ans)
