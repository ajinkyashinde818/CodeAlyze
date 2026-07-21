import sys
input = sys.stdin.readline

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

def main():
    n = int(input())
    cache = set()
    a = prime_factorize(n)
    tmp = 1
    ans = 0
    while a:
        x = a.pop()
        if tmp % x == 0:
            tmp *= x
        else:
            tmp = x
        if tmp in cache:
            continue
        cache.add(tmp)
        ans += 1
        tmp = 1


    print(ans)


main()
