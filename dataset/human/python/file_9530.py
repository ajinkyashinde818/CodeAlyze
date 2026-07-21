def main():
    N, K = map(int, input().split())
    A = list(map(int, input().split()))
    path = [-1] * N * 2
    idx = 0
    visited = [False] * N
    cur = 0
    loop = -1
    while K:
        K -= 1
        if loop == -1 and visited[cur]:
            loop = idx - path.index(cur)
            K %= loop
        path[idx] = cur
        visited[cur] = True
        cur = A[cur] - 1
        idx += 1
    print(cur + 1)


if __name__ == "__main__":
    main()
