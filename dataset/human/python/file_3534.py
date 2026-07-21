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
N = int(input())


li =  prime_factorize(N)
li_=[]
for i in set(li):
    co = li.count(i)
    counter = 0
    count = 0
    while True:
        if co< count:
            break
        else:
            counter += 1
            count += counter
    li_.append(counter-1)
print(sum(li_))
