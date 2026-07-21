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

num = int(input())
maxnum = num
l = prime_factorize(num)
if(num == 1):
    print(0)
elif(len(l)==0):
    print(1)
else:
    cnt = 0
    list=list(dict.fromkeys(l))
    for i in list:
        for n in range(maxnum):
            if(num%(i**(n+1))==0):
                num = num/(i**(n+1))
                cnt += 1
            else:
                break
    print(cnt)
