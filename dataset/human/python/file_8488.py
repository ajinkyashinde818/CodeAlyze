def resolve():
    K, N = list(map(int, input().split()))
    A = list(map(int, input().split()))
    A.sort()
    dist = []
    for i in range(N-1):
        dist.append(A[i + 1] - A[i])
    dist.append(abs(A[0] + K - A[-1]))

    print(sum(dist)-max(dist))
    return


resolve()
