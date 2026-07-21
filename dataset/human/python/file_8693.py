def main():
    K, N = map(int, input().split())
    A = list(map(int, input().split()))

    max_dist = 0
    A.append(K + A[0])

    for i in range(N):
        max_dist = max(max_dist, A[i+1] - A[i])

    print(K - max_dist)


if __name__ == '__main__':
    main()
