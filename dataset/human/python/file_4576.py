import math
n=int(input())
def factorize(n):
    fct = []  # prime factor
    b, e = 2, 0  # base, exponent
    while b * b <= n:
        while n % b == 0:
            n = n // b
            e = e + 1
        if e > 0:
            fct.append([b, e])
        b, e = b + 1, 0
    if n > 1:
        fct.append([n, 1])
    return fct
def ff(x):
    temp=(-1+math.sqrt(1+8*x))/2
    return int(temp)
s=0
x=factorize(n)
for i in x:
    s+=ff(i[1])
    
    
if(n==1):
    print(0)
else:
    print(s)
