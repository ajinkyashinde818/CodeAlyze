import collections


def f(x):  # 何個取り出せるか
    if x == 0:
        return 0
    elif 1 <= x <= 2:
        return 1
    elif 3 <= x <= 5:
        return 2
    elif 6 <= x <= 9:
        return 3
    elif 10 <= x <= 14:
        return 4
    elif 15 <= x <= 20:
        return 5
    elif 21 <= x <= 27:
        return 6
    elif 28 <= x <= 35:
        return 7
    elif 36 <= x <= 44:
        return 8
    else:
        return 9



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
    quit()

c = collections.Counter(prime_factorize(n))
cl = c.values()

ans = 0
for i in cl:
    ans += f(i)

if ans == 0:
    print(1)
else:
    print(ans)
