import math 

def prime(n):
    
    while n % 2 == 0: 
        if 2 in lis:
            lis[2] = lis[2] + 1
        else:
            lis[2] = 1
            
        n = n // 2

    for i in range(3,int(math.sqrt(n))+1,2): 
          
        while n % i== 0: 
            if i in lis:
                lis[i] = lis[i] + 1
            else:
                lis[i] = 1
            n = n // i 

    if n > 2: 
        if n in lis:
            lis[n] = lis[n] + 1
        else:
            lis[n] = 1


x = int(input())
lis = {}
prime(x)
total = 0

for i in lis:
    temp = 0
    rSum = 0

    while lis[i] > rSum:
        temp = temp + 1
        rSum = rSum + temp

    if lis[i] == rSum:
        total = total + temp
    else:
        total = total + temp-1

print(total)
