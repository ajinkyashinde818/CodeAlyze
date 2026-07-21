def prime(n):
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
    return list(set(a))
x=int(input())
p=prime(x)
s=0

for j in p:
    i=1
    while x%(j**i)==0:
        x=x//(j**i)
        s+=1
        i+=1
print(s)
