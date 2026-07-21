import math
from sys import exit

n=int(input())
primes = {}
i = 2
ans = 0
square = math.floor(math.sqrt(n))

if n == 1:
    print(0)
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

primes = factorization(n)

for k,v in primes:
    base = v * 2
    root = math.floor(math.sqrt(base))
    if root * (root + 1) > base:
        root -= 1
    ans += root

print(ans)
