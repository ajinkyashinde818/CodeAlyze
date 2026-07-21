import sys
from collections import deque

read = sys.stdin.read
readline = sys.stdin.readline
readlines = sys.stdin.readlines
sys.setrecursionlimit(10 ** 9)
INF = 1 << 60
MOD = 1000000007


def main():
    N, M, *AB = map(int, read().split())
    G = [[] for _ in range(N)]
    for a, b in zip(*[iter(AB)] * 2):
        G[a - 1].append(b - 1)
        G[b - 1].append(a - 1)

    dist = [-1] * N
    dist[0] = 0
    queue = deque([0])
    while queue:
        v = queue.popleft()
        for nv in G[v]:
            if dist[nv] == -1:
                dist[nv] = dist[v] + 1
                queue.append(nv)

    if dist[N - 1] in (1, 2):
        print('POSSIBLE')
    else:
        print('IMPOSSIBLE')

    return


if __name__ == '__main__':
    main()
