import sys
sys.setrecursionlimit(2147483647)



n=int(input())
if n==1:
    print(0)
    exit()

import math
def isPrime(num):
    if num < 2: return False
    elif num == 2: return True
    elif num % 2 == 0: return False
    for i in range(3, math.floor(math.sqrt(num))+1, 2):
        if num % i == 0:
            return False
    return True

if isPrime(n):
    print(1)
    exit()

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

sisu=(factorization(n))
#print(sisu)
cnt=0
for item in sisu:
    i=1
    tmp=item[1]
    while tmp>=i:
        tmp-=i
        cnt+=1
        i+=1

print(cnt)
