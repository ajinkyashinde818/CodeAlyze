import sys

n, k = map(int, input().split())
a = list(map(int, input().split()))
a = [0] + a

visited = set([])
hist = [-1 for _ in range(n+1)]
cur = 1
cnt = 0
d = 0

while True:
    if cnt == k:
        print(cur)
        sys.exit()
    if hist[cur] != -1:
        d = cnt - hist[cur]
        break
    hist[cur] = cnt
    cur = a[cur]
    cnt += 1

k -= hist[cur]
index = hist[cur] + k % d
# print(hist)

for i, histi in enumerate(hist):
    if index == histi:
        print(i)
        sys.exit()
