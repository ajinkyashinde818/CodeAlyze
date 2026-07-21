import math

N=int(input())

criterion=math.sqrt(N)
divisor=[]
for i in range(2,int(criterion+1)):
    if N%i==0:
        times=0
        while True:
            times+=1
            N//=i
            if (N%i)!=0:
                divisor.append((i,times))
                break

if N>criterion:
    divisor.append((N,1))

ans=0
for i in range(len(divisor)):
    num=1
    times=1
    while True:
        num+=1
        if  divisor[i][1]<times+num:
            ans+=num-1
            break
        times+=num

print(ans)
