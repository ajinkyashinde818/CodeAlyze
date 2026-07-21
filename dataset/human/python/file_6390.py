def f(n):
    if n < 2:
        return 1
    else:
        return n * f(n - 2)


def count5(n):
    d = 5
    while d < n:
        d *= 5
    c = 0
    while d != 1:
        c += n / d
        d /= 5
    return c


def main():
    n = input()
    if n % 2 == 1:
        print 0
    else:
        print min(count5(n / 2), n / 2)


main()
