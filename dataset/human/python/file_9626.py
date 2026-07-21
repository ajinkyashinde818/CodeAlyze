from collections import defaultdict

N, K = map(int, input().split())

A = [int(x) - 1 for x in input().split()]

cur = 0
step = 0
d = defaultdict(int)
d[0] = step
li = []
while True:
    cur = A[cur]
    li.append(cur)
    if d[cur] != 0:
        break
    step += 1
    d[cur] = step

pre = li[:d[cur]]
loop = li[d[cur]:]

if K <= len(pre):
    print(pre[K - 1] + 1)
else:
    K -= len(pre) + 1
    print(loop[K % (len(loop))] + 1)
