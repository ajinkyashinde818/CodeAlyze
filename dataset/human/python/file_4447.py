from collections import Counter
import math

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

n = int(input())
a = prime_factorize(n)
count = Counter(a)

ans = 0
for cnt in count.values():
    fib = 0
    for i in range(1, 41):
        fib += i
        if cnt < fib:
            ans += i - 1
            break
print(ans)
