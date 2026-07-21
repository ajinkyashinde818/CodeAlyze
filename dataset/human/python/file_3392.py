n = int(input())


def prime_factorize(n):
    map = {}
    while n % 2 == 0:
        if 2 in map:
            map[2]+=1
        else:
            map[2]=1
        n //= 2
    f = 3
    while f * f <= n:
        if n % f == 0:
            if f in map:
                map[f]+=1
            else:
                map[f]=1
            n //= f
        else:
            f += 2
    if n != 1:
        if n in map:
            map[n]+=1
        else:
            map[n]=1
    return map

map = prime_factorize(n)

count = 0
for key in map:
    k = 1
    while map[key] >= k:
        map[key]-=k
        count+=1
        k+=1
print(count)
