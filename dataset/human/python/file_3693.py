import sys

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


N = int(sys.stdin.readline().strip())

decomposed = factorization(N)
# print(decomposed)

if decomposed == [[1, 1]]:
	print(0)
	sys.exit()

ans = 0
for factor, count in decomposed:
	for i in range(10000):
		if count < i*(i+1) // 2:
			ans += i-1
			break

print(ans)
