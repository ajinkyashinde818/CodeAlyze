import collections
n = int(input())
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
c =  collections.Counter(prime_factorize(n))
a = c.values()
# print(a)
count =0
for i in a:
    k=1
    for j in range(n):
        if (i==1):
            count+=1
            break
        i-=k
        k +=1
        # print(i,k-1)
        count +=1
        if (i<=k-1):
            break
    
print(count)
