def resolve():
    n, k = map(int, input().split())
    a = [int(x) - 1 for x in input().split()]
    dist = [-1] * n
    dist[0] = 0
    now = 0
    road = [0]
    while True:
        nxt = a[now]
        if dist[nxt] < 0:
            dist[nxt] = dist[now] + 1
            now = nxt
            road.append(now)
        else:
            first = dist[now] + 1
            roop = first - dist[nxt]
            break
    if k < first:
        print(road[k] + 1)
        return
    k -= first - roop
    k %= roop
    print(road[first - roop + k] + 1)


if __name__ == '__main__':
    resolve()
