def main():
    n = int(input())
    A = [int(i) for i in input().split()]
    cul_sum = [0] * (n + 1)

    for i in range(1, n + 1):
        cul_sum[i] = cul_sum[i - 1] + A[i - 1]

    ans = float("inf")

    for i in range(1, n):
        ans = min(abs(cul_sum[i] - (cul_sum[n] - cul_sum[i])), ans)

    print(ans)


if __name__ == "__main__":
    main()
