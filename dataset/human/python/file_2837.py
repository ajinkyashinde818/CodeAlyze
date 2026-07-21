def get_input(data_type=int, container_type=list):
    return container_type(data_type(x) for x in input().split())


def is_prime(x):
    for y in range(2, x):
        yy = y ** 2
        if yy > x:
            break
        elif yy == x:
            return False
        elif x % y == 0:
            return False
    return True


def get_divs(x):
    divs = []
    for y in range(2, x):
        yy = y ** 2
        if yy > x:
            break
        elif yy == x and is_prime(y):
            divs.append(y)
        elif x % y == 0:
            if is_prime(y):
                divs.append(y)
            if is_prime(x // y):
                divs.append(x // y)
    if not divs and x > 1:
        divs.append(x)
    return divs


def get_exponents(x, divs):
    ex = []
    for y in divs:
        e = 0
        while x % y == 0:
            x //= y
            e += 1
        ex.append(e)
    return ex


def solve(x):
    divs = get_divs(x)
    ex = get_exponents(x, divs)
    sol = 0
    for e in ex:
        ee = e
        for i in range(1, e+1):
            if ee - i >= 0:
                sol += 1
                ee -= i
    return sol


N, = get_input()

print(solve(N))
