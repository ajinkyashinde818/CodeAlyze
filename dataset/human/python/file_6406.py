import math


def solve_even(n):
    assert(n % 2 == 0)
    k = n // 2
    return leg(k)


def leg(k):
    return sum(k // 5 ** i for i in range(1, int(math.log(k) / math.log(5)) + 1))


n = int(input())

if n % 2 == 0:
    if n == 0:
        print(0)
    else:
        print(solve_even(n))
else:
    if n == 1:
        print(0)
    else:
        print(solve_even(n + 1) - leg(n // 2 + 1))

# (2k + 1)!! = (2k + 2)! / (2^(k+1)*(k+1)!)
