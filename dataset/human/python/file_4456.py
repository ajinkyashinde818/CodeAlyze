import math
N = int(input())
ruteN = math.ceil(math.sqrt(N))
prime=[1]*(ruteN+2)
prime[0]=0
primes=[]
count=0
for i in range(2,ruteN+2,1):
    if prime[i]==1:
        primes.append(i)
        count+=1
        for j in range(i*2,ruteN+2,i):
            prime[j]=0

ans =0
for i in range(0,count,1):
    tmp = primes[i]
    while True:
        if N%tmp==0:
            ans += 1
            N = N//tmp
        else:
            while N % primes[i] == 0:
                N=N//primes[i]
            break
        tmp = tmp*primes[i]

if N!=1:
    ans +=1
print(ans)
