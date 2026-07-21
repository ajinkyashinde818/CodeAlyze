import math

def append_factors(n, f, p):
    num_factors = 0
    while n % p == 0:
        num_factors += 1
        n //= p
    if num_factors != 0:
        f[p] = num_factors
    return n

def factors(n):
    ret = {}
    n = append_factors(n, ret, 2)
    n = append_factors(n, ret, 3)
    i = 6
    while i*i <= n + 1:
        p1, p2 = i - 1, i + 1
        n = append_factors(n, ret, i - 1)
        n = append_factors(n, ret, i + 1)
        i += 6
    if n != 1:
        ret[n] = 1

    return ret

def minimum_sum(x):
    # find the minimum integer n where n(n+1)/2 <= x
    # n(n+1) <= 2x < (n+1)(n+2)

    n = int(math.sqrt(2 * x))
    while n*(n + 1) > 2*x:
        n -= 1

    return n

def main():
    N = int(input())
    fs = factors(N)
    # print(fs)
    ans = 0
    for f in fs:
        ans += minimum_sum(fs[f])
    print(ans)

if __name__ == '__main__':
    main()
