def resolve():
    N, K = map(int, input().split())
    A = list(map(lambda x: int(x) - 1, input().split()))

    visited = set()  # 探索済み
    path = []  # 探索順番
    now = 0
    while now not in visited:
        path.append(now)
        visited.add(now)
        now = A[now]

    s = path.index(now)
    r = len(path) - s

    if K < s:
        print(path[K] + 1)
    else:
        mod = (K - s) % r
        print(path[mod + s] + 1)

if __name__ == "__main__":
    resolve()
