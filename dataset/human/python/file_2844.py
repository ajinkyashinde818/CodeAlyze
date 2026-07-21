import math
import numpy as np
def is_prime(n):
    if n == 1:
        return False
    for i in range(2,int(n**0.5)+1):
        if n % i == 0:
            return False
    return True
def prime_factor(n):
    ass = {}
    for i in range(2,int(n**0.5)+1):
        while n % i==0:
            if i not in ass:
                ass[i]=1
            else:
                ass[i]+=1
            n = n//i
    if n != 1:
        if n not in ass:
            ass[n]=1
        else:
            ass[n]+=1
    return ass
N=int(input())
if N==1:
    print(0)
    exit()
if is_prime(N):
    print(1)
    exit()
primelist=prime_factor(N)
num_list=[]
ans=0
for i,j in primelist.items():
    for k in range(1,j+1):
        num_list.append(i**k)
for i in num_list:
    if N%i==0:
        ans+=1
        N/=i
print(ans)
