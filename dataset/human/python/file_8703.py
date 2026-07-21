def main():
    K, N = map(int, input().split(' '))
    A = list(map(int, input().split()))
    A.sort()
    A.append(A[0] + K)
    max_diff = A[0] + K - A[-1]
    for a, b in zip(A, A[1:]):
        if (b - a) > max_diff:
            max_diff = b - a
    print(K - max_diff)


if __name__ == '__main__':
    main()
