def main():
    K, N = map(int, input().split())
    A = list(map(int, input().split()))
    diff = [A[i + 1] - A[i] for i in range(N - 1)]
    diff.append(A[0] + K - A[-1])
    print(K-max(diff))

if __name__ == '__main__':
    main()
