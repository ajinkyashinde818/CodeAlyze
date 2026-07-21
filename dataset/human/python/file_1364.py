import math
import string
import collections
from collections import Counter
from collections import deque
from decimal import Decimal


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
n = int(input())
a = readints()
# print(a)
sum_a = sum(a)
ans = 10**19
s = [0]*(n+1)
for i in range(n-1):
    s[i+1] = s[i]+a[i]
    # print(s[i+1])
    tmptmp = sum_a-s[i+1]
    #print('tmp', tmp)
    #print('tmptmp', tmptmp)
    x = abs(s[i+1]-tmptmp)
    ans = min(ans, x)
print(ans)
