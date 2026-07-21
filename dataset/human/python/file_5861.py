def main():
    N = int(input())
    A = list(map(int, input().split()))
    B = list(map(int, input().split()))
    C = list(map(int, input().split()))
    p = -1
    r = 0
    for i in range(N):
        r += B[A[i]-1]
        if p + 1 == A[i]:
            r += C[p - 1]
        p = A[i]
    return r
print(main())
