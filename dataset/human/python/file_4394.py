def prime_factorize(n):
    a = []
    while n % 2 == 0:
        a.append(2)
        n //= 2
    f = 3
    while f * f <= n:
        if n % f == 0:
            a.append(f)
            n //= f
        else:
            f += 2
    if n != 1:
        a.append(n)
    return a

N=int(input())
if N==1:
	print(0)
	exit()


arr=prime_factorize(N)
kaisu=0
####################

#print(arr)

while(len(arr)>0):
	#print(arr)

	minval = min(arr)
	c=arr.count(minval)
	lp=c
	
	for i in range(1,lp+1):
		#print(i)
		if c >= i:
			c-=i
			kaisu+=1
			#print(kaisu)
		arr.remove(minval)

print(kaisu)
