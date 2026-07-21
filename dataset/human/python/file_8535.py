def main():
    K, N = map(int, input().split())
    A = list(map(int, input().split()))
    A += [K+A[0]]
    ans = K
    for i in range(N):
        ans = min(ans, K - (A[i+1] - A[i]))
    print(ans)


if __name__ == "__main__":
    main()
