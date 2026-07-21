import math


def primefac(x):
    fac = []
    for i in range(2, int(math.sqrt(x)) + 1 + 1):
        if x % i != 0:
            continue
        ex = 0
        while x % i == 0:
            ex += 1
            x = x // i
        fac.append((i, ex))

    if x != 1:
        fac.append((x, 1))
    return fac


def ans(fac):
    count = 0
    for _, ex in fac:
        for i in range(1, 10 ** 12):
            ex -= i
            if ex < 0:
                break
            else:
                count += 1
    return count


if __name__ == "__main__":
    N = int(input())
    fac = primefac(N)
    # print(fac)
    print(ans(fac))
