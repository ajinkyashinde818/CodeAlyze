def resolve():
    K, N = map(int, input().split())
    A = tuple(map(int, input().split()))
    diff_max = 0
    A_sum = 0

    for i in range(N):
        if i == N-1:
            diff = K-A[i]+A[0]
        else:
            diff = A[i+1] -A[i]

        diff_max = max(diff_max, diff)
        A_sum += diff

    print(A_sum - diff_max)
    
if __name__ == '__main__':
    resolve()
