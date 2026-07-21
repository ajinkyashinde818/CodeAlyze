N = int(input())

def make_divisors(n):
    divisors = []
    for i in range(1, int(n**0.5)+1):
        if n % i == 0:
            divisors.append(i)
            if i != n // i:
                divisors.append(n//i)

    divisors.sort()
    return divisors

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

lst = list(make_divisors(N))
#print(lst)
#print(len(lst))
cnt = 0
#print(lst)

lst2 = []

for i in lst:
    if len(set(prime_factorize(i))) == 1:
        lst2.append(i)
#print(lst2)

for i in range(len(lst2)):
    if N > 1:
        if N%lst2[i] == 0:
            N = N//lst2[i]
            cnt+=1
            #print(N)
            #print(lst2[i])
            #print(N)
#print()
print(cnt)
