def main():
    from collections import deque
    N, M = (int(i) for i in input().split())
    edge = [[] for _ in range(N)]
    for i in range(M):
        a, b = (int(i) for i in input().split())
        edge[a-1].append(b-1)
        edge[b-1].append(a-1)

    def bfs(G, s):
        dist = [-1 for _ in range(N)]
        que = deque()
        dist[s] = 0
        que.append(s)
        while que:
            u = que.popleft()
            for v in G[u]:
                if dist[v] != -1:
                    continue
                dist[v] = dist[u] + 1
                que.append(v)
        return dist

    d = bfs(edge, 0)
    if 0 <= d[N-1] <= 2:
        print("POSSIBLE")
    else:
        print("IMPOSSIBLE")


if __name__ == '__main__':
    main()
