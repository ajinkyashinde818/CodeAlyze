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
f=prime_factorize(n)
c = collections.Counter(f)
count=0
res={}
for i in range(len(f)):
    num=c[f[i]]#素数f[i]の個数
    for j in range(1,num+1):
        if f[i]**j not in res:
            res[f[i]**j]=1
            count+=1
            c[f[i]]-=j
            break
print(count)
