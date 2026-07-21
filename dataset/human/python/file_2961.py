from collections import Counter
N = int(input())
 
def prime_factorization(n):
    table = []
    for x in range(2, int(n ** 0.5) + 1):
        while n % x == 0:
            table.append(x)
            n //= x
    if n > 1:
        table.append(n)
    return table
 
T = prime_factorization(N)
C = Counter(T)
 
cnt = 0
for v in C.values():
    next = 1
    while v >= next:
        v -= next
        cnt += 1
        next += 1
 
print(cnt)
