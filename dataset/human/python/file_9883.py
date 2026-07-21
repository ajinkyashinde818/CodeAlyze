def abc167_d():
    N, K = map(int, input().split())
    A = list(map(int, input().split()))

    base, cycle = 0, 0
    order = [-1] * N
    order[0] = 0
    cnt = 1
    idx = A[0] - 1
    while True:
        if order[idx] == -1:
            order[idx] = cnt
            cnt += 1
            idx = A[idx] - 1
            continue
        base = order[idx]
        cycle = cnt - order[idx]
        break

    if base + cycle <= K:
        rest = (K - base) % cycle
        ans = order.index(base + rest) + 1
    else:
        ans = order.index(K) + 1
    print(ans)

abc167_d()
