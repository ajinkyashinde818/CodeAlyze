import sys

N, K = map(int, input().split())
A = list(map(int, input().split()))

alr = {}
now = 1
i = 0
while not now in alr.keys():
    alr[now] = i
    now = A[now-1]
    i += 1
    if i == K:
        print(now)
        sys.exit()

place = alr[now]
circle = len(alr) - place
rem = (K - place) % circle
for k, v in alr.items():
    if v == place + rem:
        print(k)
        break
