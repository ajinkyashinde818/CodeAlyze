def main():

    K, N = map(int, input().split())
    A = list(map(int, input().split()))
    A = sorted(A)
    max_dist = A[0] + (K - A[-1])
    for i in range(N - 1):
        if max_dist < A[i + 1] - A[i]:
            max_dist = A[i + 1] - A[i]
    print(K - max_dist)


if __name__ == '__main__':
    main()
