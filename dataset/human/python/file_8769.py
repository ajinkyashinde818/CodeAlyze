def resolve():
    K, N = map(int, input().split())
    A = tuple(map(int, input().split()))
    t = [0] * len(A)
    max_v = K - A[-1] + A[0]
    curr_sum = max_v
    for i in range(1, len(A)):
        max_v = max(max_v, A[i] - A[i-1])
        curr_sum += A[i] - A[i-1]
    print(curr_sum - max_v)

resolve()
