import sys
import time
input = sys.stdin.buffer.readline
def getN():
    return int(input())
def getNM():
    return map(int, input().split())
def getlist():
    return list(map(int, input().split()))
import math
import heapq
import bisect
from collections import defaultdict, Counter, deque
MOD = 10**9 + 7
INF = 10**21


def dijkstra(graph, start, n):
    h = []
    heapq.heappush(h, (0, start))
    costs = [INF for _ in range(n)]
    while h:
        cost, cur = heapq.heappop(h)
        if costs[cur] != INF:
            continue
        costs[cur] = cost
        for edge in graph[cur]:
            ecost, tgt = edge
            if costs[tgt] == INF:
                heapq.heappush(h, (cost + ecost, tgt))

    return costs


def dist(x1, y1, x2, y2):
    return math.sqrt(abs(x1 - x2) ** 2 + abs(y1 - y2) ** 2)


def main():
    xs, ys, xe, ye = getlist()
    N = getN()
    graph = [[] for i in range(N + 3)]
    circles = []
    circles.append([xs, ys, 0])
    circles.append([xe, ye, 0])
    for i in range(N):
        circles.append(getlist())

    for i in range(N+1):
        for j in range(i+1, N+2):
            # print(i, j)
            x1, y1, r1 = circles[i]
            x2, y2, r2 = circles[j]
            ray = max(dist(x1, y1, x2, y2) - r1 - r2, 0)
            graph[i].append((ray, j))
            graph[j].append((ray, i))

    print(dijkstra(graph, 0, N+2)[1])

if __name__ == '__main__':
    main()
