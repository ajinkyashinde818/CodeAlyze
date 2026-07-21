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
	exit()
l = factorization(n)

ans = 0
for i in range(len(l)):
	num = l[i][1]
	tmp = 1
	count = 0
	while True:
		if num < 0:
			ans += count - 1
			break
		num -= tmp
		tmp += 1
		count += 1
print(ans)
