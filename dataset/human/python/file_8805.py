import numpy

k, n = map(int, input().split())
a = list(map(int, input().split()))

a.sort()

diff = []
for i in range(len(a) - 1):
    diff.append(a[i + 1] - a[i])
diff.append(k - a[-1] + a[0])

max_diff = max(diff)
print(k - max_diff)
