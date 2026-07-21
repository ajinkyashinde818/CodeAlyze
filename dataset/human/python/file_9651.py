import sys

n, k = map(int, input().split())
a = list(map(int, input().split()))

town = [0] * n
town[0] = 1
track = [1]
now = 1
cnt = 0
while True:
    now = a[now-1]
    town[now-1] += 1
    cnt += 1
    if town[now-1] > 1:
        loop = now
        break
    track.append(now)
    if cnt == k:
        print(now)
        sys.exit()

idx = track.index(loop)
ans = (k - idx) % (cnt - idx)
print(track[idx:][ans])
