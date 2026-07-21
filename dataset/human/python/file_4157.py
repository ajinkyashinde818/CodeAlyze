def prime_factorizarion(n):
	arr = []
	temp = n
	for i in range(2, int(n**0.5)+1):
		if temp%i==0:
			cnt=0
			while temp%i==0:
				cnt+=1
				temp//=i
			arr.append([i,cnt])
	
	if temp!=1:
		arr.append([temp,1])
	
	if arr==[]:
		arr.append([n,1])
	
	return arr

N=int(input())
if N==1:
    print(0)
    exit()
primes=prime_factorizarion(N)

ans=0
for prime,count in primes:
    cnt=1
    tmp=1
    while True:
        if tmp>count:
            break
        ans+=1
        cnt+=1
        tmp+=cnt
print(ans)
