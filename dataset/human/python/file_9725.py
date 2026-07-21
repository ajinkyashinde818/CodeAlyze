def resolve():
    N, K = map(int, input().split())
    A = list(map(int, input().split()))

    loop = [1]
    arrived = [0] * N
    now = 1
    arrived[now - 1] = 1

    for i in range(K):
        now = A[now - 1]
        if arrived[now - 1] == 0:
            arrived[now - 1] = 1
            loop.append(now)
        else:
            loop = loop[loop.index(now):]
            arrive = loop[(K - (i + 1)) % len(loop)]
            print(arrive)
            return

    print(now)

resolve()
