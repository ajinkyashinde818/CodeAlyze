from collections import Counter
n = int(input())

def prime_factor(n):
    ass = []
    for i in range(2, int(n**0.5)+1):
        while n % i == 0:
            ass.append(i)
            n = n//i
    if n != 1:
        ass.append(n)
    return ass


prime = prime_factor(n)
#print(prime)
c = Counter(prime)
count = 0
already = []
for p in prime:
    if p not in already:
        already.append(p)
        x = c[p]
        i = 1
        while x >= i:
            x -= i
            i += 1
            count += 1

print(count)
