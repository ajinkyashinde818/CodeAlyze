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
N=int(input())
fct = factorize(N)
count=0
if fct :
    for i in range(len(fct)):
        tmp=1
        while True:
            if fct[i][1]>=tmp:
                fct[i][1]=fct[i][1]-tmp
                tmp+=1
                count+=1
            else:
                break
    print(count)
else:
    print("0")
