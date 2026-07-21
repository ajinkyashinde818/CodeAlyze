import sys
input = sys.stdin.readline

k, n = map(int, input().split())
a = list(map(int, input().split()))
gap = a[0] + k - a[n - 1]
for i in range(n - 1):
    gap = max(gap, a[i + 1] - a[i])
print(k - gap)
