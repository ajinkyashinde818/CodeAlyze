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

n=int(input())
arr=factorization(n)
num=[1,3,6,10,15,21,28,36,45,55,66]

res=0
for x,y in arr:
	 for i in num:
	 	if y>=i:
	 		res+=1

if n==1:
	print("0")
else:
	print(res)
