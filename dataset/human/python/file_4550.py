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
import math
N = int(input())
A = prime_factorize(N)
B = list(set(A))
kosuu = [0]*len(B)
ans = 0
for i in range(len(B)):
    kosuu[i] = A.count(B[i])
for i in range(len(kosuu)):
    for j in range(1, int(math.sqrt(N))):
        kosuu[i] -= j
        if kosuu[i] >= 0:
            ans += 1
        else:
            break
print(ans)
