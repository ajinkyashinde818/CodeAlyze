def resolve():
    N, K = list(map(int, input().split()))
    A = list(map(lambda x: int(x)-1, input().split()))
    routes = [0]
    current = 0
    visited = [False for _ in range(N)]
    visited[0] = True
    while visited[A[current]] is False:
        current = A[current]
        routes.append(current)
        visited[current] = True
    leftlen = routes.index(A[current])
    repeat = routes[leftlen:]
    # print(leftlen)
    # print(routes)
    # print(repeat)
    print(repeat[(K-leftlen)%len(repeat)]+1 if K > leftlen else routes[K]+1)


if '__main__' == __name__:
    resolve()
