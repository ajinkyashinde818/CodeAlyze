def C():
    K, N = map(int, input().split())
    A = [int(n) for n in input().split()]
    minimum_distance = A[-1] - A[0]
    for i in range(1, N):
        minimum_distance = min(minimum_distance, K - A[-i] + A[-i-1])
    print(minimum_distance)
            
C()
