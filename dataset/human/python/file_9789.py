def resolve():
    N, K = map(int, input().split())
    A = tuple(map(int, input().split()))
    path = [1]
    for i in range(2*N):
        cur = A[path[-1]-1]
        path.append(cur)

    if K < N:
        print(path[K])
        exit()

    end = N
    si = N-1
    while path[si] != path[end]:
        si -= 1
    dist = end - si
    K = K % dist
    while K < N:
        K += dist

    print(path[K])

if __name__ == '__main__':
    resolve()
