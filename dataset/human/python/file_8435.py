def main(k, n, A):
    distances = [A[0] + k-A[-1]]

    for i in range(1, n):
        distances.append(A[i] - A[i-1])

    print(k - max(distances))


if __name__ == "__main__":
    k, n = map(int, input().split())
    A = list(map(int, input().split()))

    main(k, n, A)
