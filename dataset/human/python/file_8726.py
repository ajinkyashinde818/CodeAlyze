def solve():
    K, N = map(int, input().split())
    A = list(map(int, input().split()))
    a = A[-1] - A[0]
    
    ma = 0
    for i in range(N-1):
        ma = max(ma, A[i+1]-A[i])
    
    return min(a, K-ma)

print(solve())
