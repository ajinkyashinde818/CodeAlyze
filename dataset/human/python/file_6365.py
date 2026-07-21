from fractions import gcd

def read():
    N = int(input().strip())
    return N,


def list_multiple_of_5(n):
    base = []
    mul = 5
    while mul <= n:
        base.append(mul)
        mul *= 5
    return base

def solve(N):
    if N % 2 == 1:
        return 0
    count = 0
    base10 = N // 10
    count += base10
    m5s = list_multiple_of_5(base10)
    for m5 in m5s:
        count += (base10 // m5)
    return count


if __name__ == '__main__':
    inputs = read()
    print("%d" % solve(*inputs))
