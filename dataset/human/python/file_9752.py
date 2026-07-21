def resolve():
    N, K = map(int, input().split())
    A = list(map(int, input().split()))
    A.insert(0, 0)

    route = [1]
    route_set = set(route)
    towns_step = [0] * (N+10)
    step = 0
    now = 1
    while A[now] not in route_set:
        next = A[now]
        route.append(next)
        route_set.add(next)
        step += 1
        towns_step[next] = step
        now = next

    border = towns_step[A[now]]
    head = route[0: border]
    roop = route[border:]

    if K < border:
        ans = head[K]
    else:
        k = (K - border) % len(roop)
        ans = roop[k]
    print(ans)

if __name__ == "__main__":
    resolve()
