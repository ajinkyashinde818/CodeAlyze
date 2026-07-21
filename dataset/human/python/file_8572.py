import sys

k, n = map(int, input().split())
a = list(map(int, input().split()))

def calcr(k, n, start, a):
    if start == 0:
        return a[n - 1] - a[0]
    else:
        return k - a[start] + a[start - 1]

def calcl(k, n, start, a):
    if start == n - 1:
        return a[n - 1] - a[0]
    return a[start] + k - a[start + 1]

mindist = calcr(k, n, 0, a)
for i in range(n):
    mindist = min(mindist, calcr(k, n, i, a))
    mindist = min(mindist, calcl(k, n, i, a))

print(mindist)
