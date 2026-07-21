n = int(input())


def solve(n):
    res = 0
    for d in range(2, n):
        if d * d > n:
            break

        degree = 0
        while n % d == 0:
            n /= d
            degree += 1

        i = 1
        while degree >= i:
            degree -= i
            i += 1
            res += 1

    if n > 1:
        res += 1
    return res


print(solve(n))
