import itertools
import math
import fractions
import functools
n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
c = list(map(int, input().split()))
for i in range(n):
    a[i] -= 1
sum = b[a[0]]
for i in range(1,n):
    if a[i-1] + 1 == a[i]:
        sum += b[a[i]]+c[a[i]-1]
    else:
         sum += b[a[i]]

print(sum)
