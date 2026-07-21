from collections import Counter
from functools import reduce
from operator import mul


def plus_one(n):
    return n + 1


N = int(input())
S = Counter(list(input()))

print((reduce(mul, map(plus_one, S.values())) - 1) % (10 ** 9 + 7))
