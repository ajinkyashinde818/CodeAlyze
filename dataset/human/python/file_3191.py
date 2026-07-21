import math

def factorization(n):
    r = []
    temp = n
    for i in range(2,int(math.sqrt(n))+1):
        m = 0
        while temp % i == 0:
            temp /= i
            m += 1
        if m > 0:
            r.append((i,m))
    if temp != 1:
        r.append((temp,1))
    if len(r) == 0:
        r.append((n,1))
    return r

n = int(input())
p = factorization(n)
ans = 0
if p[0][0] == 1:
    ans = 0
else:
    for x in p:
        i = 1
        s = x[1]
        while s >= i:
            s -= i
            i += 1
        ans += (i-1)
print(ans)
