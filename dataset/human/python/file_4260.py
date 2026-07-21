Number=int(input())

times=0

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
    
    if n==1:
        return []
    else:
        return arr


Factors=factorization(Number)
#print(Factors)

for i in Factors:
    Power=i[1]
    BiggerThan=0
    MinusPower=1
    
    while Power>BiggerThan:
        times+=1
        Power-=MinusPower
        MinusPower+=1
        BiggerThan+=1

print(times)
