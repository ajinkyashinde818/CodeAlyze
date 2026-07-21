import math
from heapq import heappush, heappop


def main():
    sx, sy, gx, gy = map(int, input().split())
    N = int(input())
    P = [(sx, sy, 0)] + [(gx, gy, 0)] + \
        [tuple(map(int, input().split())) for _ in range(N)]
    dist = [[0]*(N+2) for _ in range(N+2)]
    for i in range(N+2):
        for j in range(N+2):
            xi, yi, ri = P[i]
            xj, yj, rj = P[j]
            dist[i][j] = max(math.sqrt((xi-xj)**2 + (yi-yj)**2) - (ri+rj), 0.0)
    INF = float("Inf")
    ans = [INF] * (N+2)
    h = [(0.0, 0)]
    while len(h) and ans[1] == INF:
        d, i = heappop(h)
        if ans[i] != INF:
            continue
        ans[i] = d
        for j in range(N+2):
            if ans[j] == INF:
                heappush(h, (d + dist[i][j], j))
    print(ans[1])


if __name__ == "__main__":
    main()
