from collections import defaultdict, deque

n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

ns = defaultdict(int)
for i in a:
    ns[i] += 1
for i in b:
    ns[i] += 1
if max(ns.values()) > n:
    print('No')
    exit()

j = -1
k = -1
md = 0
for i in range(2, n + 1):
    while j + 1 < n and a[j + 1] < i:
        j += 1
    while k + 1 < n and b[k + 1] < i - 1:
        k += 1
    md = max(md, j - k)

for i in range(n):
    if a[i] == b[(i - md) % n]:
        md += 1
        break

d = deque(b)
d.rotate(md)

print('Yes')
print(' '.join([str(x) for x in d]))
