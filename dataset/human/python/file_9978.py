def gcd(a, b):
    x = min(a, b)
    y = max(a, b)
    if x % y == 0:
        return y
    else:
        while x % y != 0:
            z = x % y
            x = y
            y = z
        else:
            return z


def lcm(a, b):
    return int(a * b / gcd(a, b))


A, B = map(int, input().split())
print(lcm(A, B))
