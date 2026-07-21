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
count = 0

soinsuu = prime_factorize(n)

soinsuu_set = set(soinsuu)
soinsuu_list = list(soinsuu_set)


for i in range(len(soinsuu_set)):
    z = soinsuu_list[i]
    while n % z == 0:
        n = n / z 
        z = z*soinsuu_list[i]
        count = count + 1
    
print(count)
