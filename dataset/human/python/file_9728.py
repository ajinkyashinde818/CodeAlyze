from sys import stdin
n,k = map(int,stdin.readline().split())
a = list(map(int,stdin.readline().split()))
for i in range(n):
    a[i] -= 1
d = {}
d[0] = k
cur = 0
while k > 0:
    cur = a[cur]
    k -= 1
    if cur in d:
        looplen = d[cur] - k
        k %= looplen
    else:
        d[cur] = k
print(cur + 1)
