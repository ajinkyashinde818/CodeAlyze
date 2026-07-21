import itertools
import math
import fractions
import functools
k, n = map(int, input().split())
a = list(map(int, input().split()))

sub = [0] * n
for i in range(n-1):
    sub[i] = a[i+1]-a[i]

sub[n-1] = k - a[n-1] + a[0]

print(k-max(sub))
