def main():
    K, N = map(int, input().split())
    A = list(map(int, input().split()))
    dists = set([])
    for idx in range(len(A) - 1):
        dists.add(A[idx + 1] - A[idx])
    dists.add(A[0] + K - A[-1])
    print(K - max(list(dists)))


if __name__ == '__main__':
    main()
