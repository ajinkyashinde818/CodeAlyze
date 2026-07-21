def main():
    n = int(input())
    a = list(map(int, input().split()))
    for i in range(1, n):
        a[i] += a[i - 1]
    ans = float("inf")
    for i in range(n - 1):
        ans = min(ans, abs(a[-1] - 2 * a[i]))
    print(ans)


if __name__ == '__main__':
    main()
