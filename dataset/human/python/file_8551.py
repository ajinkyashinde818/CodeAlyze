from sys import stdin

k, n = [int(x) for x in stdin.readline().rstrip().split()]
a = [int(x) for x in stdin.readline().rstrip().split()]
d = max(max([abs(a[x] - a[x - 1]) for x in range(len(a)) if x > 0]), abs(a[0] + k - a[len(a)-1]))

print(k - d)
