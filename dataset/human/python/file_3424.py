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

if n==1:
    print(0)
else:
    result=factorization(n)
    primes=len(result)
    
    ans=0
    for i in range(primes):
        tmp=result[i][1]
        cnt=0
        j=1
        while 1:
            tmp-=j
            if tmp>=0:
                cnt+=1
            else:
                break
            j+=1
        
        ans+=cnt

    print(ans)
