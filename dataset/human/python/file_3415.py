N=int(input())
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
b=prime_factorize(N)
if b==1:
    print(0)
else:
    number=0
    c=list(set(b))
    for i in tuple(c):
        d=b.count(i)
        if 1<=d<=2:
            number+=1
        elif 3<=d<=5:
            number+=2
        elif 6<=d<=9:
            number+=3
        elif 10<=d<=14:
            number+=4
        elif 15<=d<=20:
            number+=5
        elif 21<=d<=27:
            number+=6
        elif 28<=d<=35:
            number+=7
        elif 36<=d<=45:
            number+=8
    print(number)
