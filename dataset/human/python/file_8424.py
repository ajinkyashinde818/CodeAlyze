def main():
    K, N = list(map(int, input().split(' ')))
    A = list(map(int, input().split(' ')))
    A.append(A[0] + K)
    distances = [A[i + 1] - A[i] for i in range(N)]
    print(K - max(distances))


if __name__ == '__main__':
    main()
