import sys

N, K = map(int, input().split())
A = list(map(int, input().split()))

cnt = 0
current = 0
roads = []
reached = [-1 for _ in range(N)]

while True:
    if reached[current] >= 0:
        initial = reached[current]
        mod = cnt - initial
        if K <= initial:
            print(roads[K]+1)
        else:
            k = (K-initial) % mod
            print(roads[initial:][k]+1)
        sys.exit()
    roads.append(current)
    reached[current] = cnt
    cnt += 1
    current = A[current] - 1
