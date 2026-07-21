import math

k, n = [int(x) for x in input().split()]
a = [int(x) for x in input().split()]

res = n-1
top = (k - a[-1]) + a[0]
for i in range(n-1):
    if a[i+1] - a[i] > top:
        top = a[i+1] - a[i]
        res = i

print (k-top)
