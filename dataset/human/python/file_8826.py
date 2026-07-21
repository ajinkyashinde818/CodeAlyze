import sys

k, n = map(int, sys.stdin.readline().split())
a = list(map(int, sys.stdin.readline().split()))
a.sort()

max_len = 0
total = 0
for i in range(n):
    if a[i] < a[i-1]:
        l = a[i] + k - a[i-1]
    else:
        l = a[i] - a[i-1]
    max_len = max(max_len, l)
    total += l

print(total-max_len)
