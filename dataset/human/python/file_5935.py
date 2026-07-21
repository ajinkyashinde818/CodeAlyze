if __name__ == '__main__':
    N = int(input())    
    A = list(map(int, input().split()))
    B = list(map(int, input().split()))
    C = list(map(int, input().split()))

    count = 0
    before = -1
    for i in range(N):
        if before == A[i] - 1:
            count += C[A[i-1]-1]
        count += B[A[i]-1]
        before = A[i]
    print(count)
