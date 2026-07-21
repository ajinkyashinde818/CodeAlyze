import itertools
import decimal
import math
import collections

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

def iskaijo(n):
    i=1
    while True:
        if(n==1):
            break
        if(n%i==0):
            n=n/i
            i=i+1
        else:
            i=-1
            break
    return i

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


N=int(input())


ng=False
ans=0
List =factorization(N)
#c=collections.Counter(List)
for i in range(len(List)):
    test = List[i][1]
    i=1
    while True:
        test=test-i
        i=i+1
        ans=ans+1
        if(test == 0):
            break
        elif(test < 0 ):
             ans=ans-1
             break
#print(List)
if N!=1:
    print(ans)
else:
    print(0)
