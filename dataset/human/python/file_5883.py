if __name__ == "__main__":
    N = int(input())
    A = list(map(int, input().split()))
    B = list(map(int, input().split()))
    C = list(map(int, input().split()))

    res = 0
    for i in range(N):
        if i > 0:
            if A[i] - A[i-1] == 1:
                res += C[A[i-1]-1]
        res += B[A[i]-1]

    print(res)
