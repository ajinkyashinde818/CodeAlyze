def resolve():
    K, N = map(int, input().split())
    A = list(map(int, input().split()))
    max_distance = 0

    for i in range(N - 1):
        max_distance = max(max_distance, A[i + 1] - A[i])

    max_distance = max(max_distance, A[0] + K - A[N - 1])
    print(K - max_distance)


resolve()
