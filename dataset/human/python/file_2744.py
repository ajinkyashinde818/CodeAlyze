import numpy as np
from functools import reduce
from operator import add,sub,mul,truediv
from fractions import gcd

d,g = map(int,input().split())

p = []
c = []

for _ in range(d):
    a,b = map(int,input().split())
    p.append(a)
    c.append(b)


ans = 1000000000

#print(p)
#print(c)
for bit in range(1 << d):
    score = 0
    num = 0
    x = []
    for i in range(d):
        if (bit >>i)&1 == 0:
            x.append(i+1)
        else:
#            print(i)
#            print(p[i])
            score  = score + p[i]*(i+1)*100+c[i]
            num = num + p[i]
    
#    print(bin(bit))
#    print(x[::-1])

    flag = False
    for j in x[::-1]:
        for _ in range(p[j-1]):
            if score >= g:
                flag = True
                break
            score  = score + j*100
            num = num +1
#            print(score)
#            print(num)
        
#        print(num)
        if flag :
            break
        
#    print(score)
#    print(num)
#    print("num:{}".format(num))
    ans= min(ans,num)
#    print("$$$$$$$$$$$$$$$$$$$$$")

print(ans)
