def main():
    K, N = map(int, input().split())
    A = list(map(int, input().split()))
    B = [0] * (2 * N)
    for i in range(2 * N):
        if i < N:
            B[i] += A[i]
        else:
            B[i] = A[i-N] + K

    ans = float('inf')

    for i in range(N):
        ans = min(ans, B[i + N - 1] - B[i])

    print(ans)



if __name__ == "__main__":
    main()
