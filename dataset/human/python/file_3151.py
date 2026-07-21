import math

def prime_factrization(n):
    factor = []
    tmp = int(math.sqrt(n)) + 1
    for num in range(2,tmp):
        while n % num == 0:
            n //= num
            factor.append(num)

    if not factor:
        return 0
    else:
        if n != 1:
            factor.append(n)
        return list(factor)

ans = 0
N = int(input())
factor = prime_factrization(N)
if N == 1:
    print(0)
elif factor == 0 and N != 1:
    print(1)
else:
    for i in list(set(factor)):
        num = factor.count(i)
        j = 1
        a = 1
        while j <= num:
            ans += 1
            a += 1
            j += a
    print(ans)
