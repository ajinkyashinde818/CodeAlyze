N = int(input())
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
A = prime_factorize(N)
b = {}
for i in A:
    if i not in b:
        b[i] = 1
    elif i in b:
        b[i] += 1
count = 0
for v in b.values():
    if v >= 45:
        count += 9
        continue
    
    elif v >= 36:
        count += 8
        continue
    elif v >= 28:
        count += 7
        continue
    elif v >= 21:
        count += 6
        continue
    
    elif v >= 15:
        count += 5
        continue
    elif v >= 10 :
        count += 4
        continue
    elif v >= 6:
        count += 3
        continue
    elif v >= 3 :
        count += 2
        continue
    elif v >= 1 :
        count += 1
        continue
#print(b)
print(count)
