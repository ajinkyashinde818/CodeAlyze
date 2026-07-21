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

N = int(input())
insu = prime_factorize(N)

insu_num = []
ans = 0

while len(insu) != 0:
    num = insu.count(insu[0])
    insu_num.append(num)
    insu = insu[num:]

for num in insu_num:
    p = 1
    while True:
        num -= p
        if num>=0:
            ans += 1
        else:
            break 
        p += 1   

print(ans)
