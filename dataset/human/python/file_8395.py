def solve():
    K, N = map(int, input().split())
    A = list(map(int, input().split()))

    max_diff = 0
    max_idx = -1
    for i in range(N-1):
        max_diff = max(max_diff, A[i+1]-A[i])
        if max_diff == A[i+1]-A[i]:
            max_idx = i
    
    else:
        max_diff = max(max_diff, K-A[-1]+A[0])
        if max_diff == K-A[-1]+A[0]:
            max_idx = N-1
    
    print(K - max_diff)

if __name__ == '__main__':
    solve()
