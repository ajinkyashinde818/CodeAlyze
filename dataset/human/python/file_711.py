import heapq


def dijkstra(adj: list, start, goal=None):
    """adj:隣接行列"""
    num = len(adj)          # グラフのノード数
    dist = [float('inf') for i in range(num)]  # 始点から各頂点までの最短距離を格納する
    prev = [float('inf') for i in range(num)]  # 最短経路における，その頂点の前の頂点のIDを格納する
    dist[start] = 0
    # プライオリティキュー．各要素は，(startからある頂点vまでの仮の距離, 頂点vのID)からなるタプル
    q = []
    heapq.heappush(q, (0, start))  # 始点をpush
    while q:
        prov_cost, src = heapq.heappop(q)  # pop
        # プライオリティキューに格納されている最短距離が，現在計算できている最短距離より大きければ，distの更新をする必要はない
        if dist[src] < prov_cost:
            continue
        # 他の頂点の探索
        for dest in range(num):
            cost = adj[src][dest]
            if cost != float('inf') and dist[dest] > dist[src] + cost:
                dist[dest] = dist[src] + cost  # distの更新
                # キューに新たな仮の距離の情報をpush
                heapq.heappush(q, (dist[dest], dest))
                prev[dest] = src                      # 前の頂点を記録
    return dist


INF = float('inf')
xs, ys, xt, yt = map(int, input().split())
n = int(input())
n += 2
li = [None] * n
li[0] = (xs, ys, 0)
li[n - 1] = (xt, yt, 0)
for i in range(n - 2):
    x, y, r = map(int, input().split())
    li[i + 1] = (x, y, r)
mat = [[INF] * n for _ in range(n)]
for i in range(n):
    mat[i][i] = 0
    for j in range(i + 1, n):
        x1, y1, r1 = li[i]
        x2, y2, r2 = li[j]
        d = ((x1 - x2) ** 2 + (y1 - y2) ** 2) ** .5
        res = max(d - r1 - r2, 0)
        mat[i][j] = res
        mat[j][i] = res
d = dijkstra(mat, 0)
print(d[n - 1])
