def divisor(x):
    ret = []
    for i in range(1, int(x ** 0.5) + 1):
        if x % i == 0:
            ret.append(i)
            ret.append(x // i)
    return sorted(list(set(ret)))

def prime_factor(n):
    ass = []
    for i in range(2, int(n ** 0.5) + 1):
        while n % i == 0:
            ass.append(i)
            n = n // i
    if n != 1:
        ass.append(n)
    return len(set(ass))==1

n = int(input())

div = divisor(n)[1:]

l=[]
for i in div:
    if prime_factor(i):
        l.append(i)

ans = 0
for i in l:
    if n % i == 0:
        ans += 1
        n //= i
 
print(ans)
