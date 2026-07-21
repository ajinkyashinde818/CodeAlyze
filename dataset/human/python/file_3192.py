import collections
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
 
n=int(input())
c= collections.Counter(prime_factorize(n))
#ここまでで素因数分解して個数が何個あるかcheckしてる
sum=0
for i in c:
    n=1
    while n*(n+1)/2<=c[i]:
        n=n+1
    sum=sum+n-1
print(sum)
