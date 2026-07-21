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

def maxsum(e):
	n = 0
	while n*(n + 1)/2 <= int(e):
		n = n + 1 
	return n - 1

def solve(N):
	if N == 1:
		return 0
	fac = factorization(N)
	sum = 0
	for ret in fac:
		sum = sum + maxsum(ret[1])
	return sum

N = input()
print(solve(N))
