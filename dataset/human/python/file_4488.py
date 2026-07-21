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

n = int(input())
if n == 1:
    print(0)
else:
    l = prime_factorize(n)
    # print(l)
    cnt = 2

    tem = l[0]
    for i in range(1, len(l)):
        if l[i] == tem:
            l[i] = tem ** cnt
            cnt += 1
        else:
            tem = l[i]
            cnt = 2

    l.sort()
    # print(l)

    cnt = 0
    i = 0
    while n != 1 and i < len(l):
        if n % l[i] == 0:
            n /= l[i]
            cnt += 1
        i += 1

    print(cnt)
