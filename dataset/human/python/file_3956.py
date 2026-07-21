import collections

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

c = collections.Counter(prime_factorize(n))

temp_list = c.values()
ans = 0

if n == 1:
    print(0)
else:
    for i in temp_list:
        temp_num = i
        temp = 1
        while temp_num >= temp:
            temp_num = temp_num - temp
            ans += 1
            temp += 1
    print(ans)
