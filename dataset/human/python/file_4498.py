def pf(n):
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
from collections import Counter 
b = Counter(pf(n))

ans = 0
for i in b:
    a = b[i]
    for i in range(1,30):
        a -= i
        if a < 0:
            break
        ans += 1
        
print(ans)
