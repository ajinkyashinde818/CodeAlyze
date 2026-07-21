def main():
    N = int(input())
    A = list(map(int, input().split()))
    total = sum(A)
    ans = float("inf")
    x = 0
    for i in range(N-1):
        x += A[i]
        ans = min(ans, abs(total - 2*x))
    print(ans)


if __name__ == "__main__":
    main()
