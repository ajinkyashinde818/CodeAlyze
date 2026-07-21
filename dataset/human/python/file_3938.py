import collections

n = int(input())

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

if n == 1:print(0)
else:
    c = collections.Counter(prime_factorize(n))
    kouho = []
    soinnsuu = list(c.keys())
    sisuu = list(c.values())
    '''for i in range(len(soinnsuu)):
        for j in range(1,sisuu[i] + 1):
            kouho.append(soinnsuu[i]**j)
    kouho = list(set(kouho))
    kouho.sort()
    ans = 0
    while n != 1:
        for i in range(len(kouho)):
            if n%kouho[i] == 0 and kouho[i] != -1:
                n //= kouho[i]
                kouho[i] = -1
                ans += 1
                break
    '''
    ans = 0
    for i in sisuu:
        for j in range(1,100):
            if i >= j:
                ans += 1
                i -= j
            else:break
    print(ans)
