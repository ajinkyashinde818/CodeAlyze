from sys import stdin, setrecursionlimit
from collections import deque


def main():
    input = stdin.buffer.readline
    n, m = map(int, input().split())
    g = [[] for _ in range(n)]
    for _ in range(m):
        a, b = map(int, input().split())
        g[a - 1].append(b - 1)
        g[b - 1].append(a - 1)

    q = deque([0])
    seen = [-1] * n
    seen[0] = 0

    while q:
        u = q.popleft()

        for v in g[u]:
            if seen[v] == -1 or seen[v] > seen[u] + 1:
                seen[v] = seen[u] + 1
                q.append(v)

    if seen[n - 1] == 2:
        print('POSSIBLE')
    else:
        print('IMPOSSIBLE')


if __name__ == "__main__":
    setrecursionlimit(10000)
    main()
