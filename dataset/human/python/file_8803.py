def calc(K, N, A):
    B = [A[i + 1] - A[i] for i in range(N - 1)] + [A[0] + K - A[N - 1]]
    return K - max(B)


(K, N) = tuple([int(s) for s in input().split()])
A = [int(s) for s in input().split()]
print(calc(K, N, A))
