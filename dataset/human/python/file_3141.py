import sys 
from collections import Counter
input = sys.stdin.readline
n = int(input())
m = int(n**0.5)

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

if n == 1:
    ans = 0
else:
    ans = 0
    a = prime_factorize(n)
    c = Counter(a)
    for val in c.values():
        j = 1
        while j*(j+1)//2 <= val:
            j += 1
        ans += j-1
print(ans)
