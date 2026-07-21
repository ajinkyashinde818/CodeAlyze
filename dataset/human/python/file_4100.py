N = int(input())

def fac(n):
    org = n

    fac = []
    i = 2
    while i * i <= org:
        if n % i == 0:
            ex = 0 # 指数
            while n % i == 0:
                ex += 1
                n //=  i
            fac.append([i, ex])
        i += 1

    if n != 1:
        fac.append([n, 1])
    return fac

def k(c):
    d = (1 + 8*c) ** (1/2)
    return (d - 1) / 2

print(sum(int(k(i[1])) for i in fac(N)))
