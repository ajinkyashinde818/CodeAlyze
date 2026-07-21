import math
import string
import collections
from collections import Counter


def readints():
    return list(map(int, input().split()))


def nCr(n, r):
    return math.factorial(n)//(math.factorial(n-r)*math.factorial(r))


def has_duplicates2(seq):
    seen = []
    for item in seq:
        if not(item in seen):
            seen.append(item)
    return len(seq) != len(seen)


def divisor(n):
    divisor = []
    for i in range(1, n+1):
        if n % i == 0:
            divisor.append(i)
    return divisor


# coordinates
dx = [-1, -1, -1, 0, 0, 1, 1, 1]
dy = [-1, 0, 1, -1, 1, -1, 0, 1]

k, n = map(int, input().split())
a = readints()
# 1→N特殊
tokusyu = (k-(k-a[n-1]+a[0]))
# 2→1（2-1)
# 3→2（3-2）

for i in range(n-1):
    tokusyu = min(tokusyu, k-(a[i+1]-a[i]))
print(tokusyu)
