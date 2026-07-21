import sys
input = sys.stdin.readline
from collections import *

def factorize(n):
    fct = []
    
    for i in range(2, int(n**0.5)+1):
        c = 0
        
        while n%i==0:
            n //= i
            c += 1
            
        if c>0:
            fct.append((i, c))
    
    if n>1:
        fct.append((n, 1))
    
    return fct

N = int(input())
fct = factorize(N)
ans = 0

for _, c in fct:
    sub = 1
    
    while c-sub>=0:
        c -= sub
        ans += 1
        sub += 1

print(ans)
