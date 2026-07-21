import collections

def prime_factorize(x):
    factor = []
    while x % 2 == 0:
        x //= 2
        factor.append(2)
    div = 3
    while div ** 2 <= x:
        if x % div == 0:
            x //= div
            factor.append(div)
        else:
            div += 2
    if x != 1:
        factor.append(x)
    return collections.Counter(factor)

n = int(input())
ans = 0
for x in prime_factorize(n).values():
    tmp = 0
    check = 1
    i = 2
    while check <= x:
        check += i
        tmp += 1
        i += 1
    ans += tmp
print(ans)
