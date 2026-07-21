n = int(input())

def divisorize(fct):
    b, e = fct.pop()  # base, exponent
    pre_div = divisorize(fct) if fct else [[]]
    suf_div = [[(b, k)] for k in range(e + 1)]
    return [pre + suf for pre in pre_div for suf in suf_div]


def factorize(n):
    fct = []  # prime factor
    b, e = 2, 0  # base, exponent
    while b * b <= n:
        while n % b == 0:
            n = n // b
            e = e + 1
        if e > 0:
            fct.append((b, e))
        b, e = b + 1, 0
    if n > 1:
        fct.append((n, 1))
    return fct


def num(fct):
    a = 1
    for base, exponent in fct:
        a = a * base**exponent
    return a


if n==1:
    print(0)
else:
    div = []
    count = 0
    fct = factorize(n)
    div += [num(div) for div in divisorize(fct)]
    div = sorted(div)
    #div = div
    for i in div[1:]:
        fct2 = factorize(i)
        if n%i==0 and len(fct2)==1:
            n = n/i
            count += 1
        if n==1:
            break
    print(count)
