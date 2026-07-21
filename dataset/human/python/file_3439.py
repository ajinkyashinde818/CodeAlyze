import math

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

l=prime_factorize(n)
c=0
ls=set(l)

ln=[]
for i in iter(ls):
    s=0
    for j in l:
        if i==j:
            s+=1
    ln.append(s)



for i in range(len(ln)):
    c+=int((math.sqrt(1+8*ln[i])-1)/2)

print(c)
