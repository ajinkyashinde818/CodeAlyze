def main():
    import sys
    input = sys.stdin.readline
    N, K = map(int, input().split())
    *A, = map(lambda x: int(x) - 1, input().split())

    t = 0
    while K:
        if K & 1:
            t = A[t]
        nA = [0] * N
        for i in range(N):
            nA[i] = A[A[i]]
        A = nA
        K >>= 1
    print(t + 1)


if __name__ == '__main__':
    main()
