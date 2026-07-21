import sys
input = sys.stdin.readline

k, n = [int(x) for x in input().split()]
a = [int(x) for x in input().split()]

a.sort()

b = []

for i in range(n - 1):
    b.append(a[i + 1] - a[i])

b.append(k - sum(b))

ans = sum(b) - max(b)

print(ans)
