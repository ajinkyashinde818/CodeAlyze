import sys

readline = sys.stdin.readline
n, k = map(int, readline().split())
A = [i - 1 for i in map(int, readline().split())]

m = 60
d = [A]
pre = A
for i in range(m):
    current = [pre[pre[j]] for j in range(n)]
    d.append(current)
    pre = current

route = 0
for i in range(m-1, -1, -1):
    if k >= (x := 1 << i):
        route = d[i][route]
        k -= x
print(route+1)
