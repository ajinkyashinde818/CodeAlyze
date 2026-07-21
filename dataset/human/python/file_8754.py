def main():
    import sys
    input = sys.stdin.readline

    K, N = map(int, input().split())
    A = list(map(int, input().split()))

    d = []
    for i in range(N-1):
        d.append(A[i+1] - A[i])
    d.append(K-A[-1]+A[0])
    print(K - max(d))


if __name__ == '__main__':
    main()
