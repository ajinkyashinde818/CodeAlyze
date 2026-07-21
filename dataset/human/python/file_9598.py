import sys

N, K = map(int, input().split())
A = list(map(int, input().split()))
d = {1: 0}
pre = 1
for i in range(1, N+1):
    new = A[pre-1]
    if d.get(new):
        roop_start = d[new]
        roop_end = i
        roop_pos = new
        break
    if i==K:
        print(new)
        sys.exit()
    d[new] = i
    pre = new

K -= roop_start
K %= roop_end-roop_start
pre = roop_pos
for i in range(K):
    pre = A[pre-1]
print(pre)
