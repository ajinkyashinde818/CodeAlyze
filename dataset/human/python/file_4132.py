n = int(input())

def factorize(n):
    fct = []  
    b, e = 2, 0  
    while b * b <= n:
        while n % b == 0:
            n = n // b
            e = e + 1
        if e > 0:
            fct.append([b, e])
        b, e = b + 1, 0
    if n > 1:
        fct.append([n, 1])
    return fct

aoinsu = factorize(n)

kaijo = [1]
b = 1
for i in range(2,10):
    b = b+i
    kaijo.append(b)

#print(kaijo)    

#print(aoinsu)

ans = 0
for i in range(len(aoinsu)):
    a = aoinsu[i][1]
    for j in range(10):
        if a < kaijo[j]:
            ans += j
            break


print(ans)
