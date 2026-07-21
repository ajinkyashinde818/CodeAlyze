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

N=int(input())
c = collections.Counter(prime_factorize(N))

X=[]
for a in c.values():
    X.append(a)
def count(a):
    if 1<=a<=2:
        return 1
    elif 3<=a<=5:
        return 2
    elif 6<=a<=9:
        return 3
    elif 10<=a<=14:
        return 4
    elif 15<=a<=20:
        return 5
    elif 21<=a<=27:
        return 6
    elif 28<=a<=35:
        return 7
    elif 36<=a<=40:
        return 8

ans=0
for i in range(len(X)):
    ans+=count(X[i])
print(ans)
