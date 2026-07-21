n = int(input())

def fctr1(n): 
    f=[]
    c=0
    r=int(n**0.5)
    for i in range(2,r+2):
        while n%i==0:
            c+=1
            n=n//i
        if c!=0:
            f.append([i,c])
            c=0
    if n!=1:
        f.append([n,1])
    return f

import math

if n == 1:
    print(0)
else:
    l = fctr1(n)
    ans = 0
    for i in l:
        ans += math.floor((-1+math.sqrt(1+8*i[1]))/2)
    print(ans)
