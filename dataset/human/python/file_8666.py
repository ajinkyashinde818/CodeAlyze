def main():
    k, n = map(int, input().split())
    a = list(map(int, input().split()))
    max_d = k - a[-1] + a[0]
    for i in range(n - 1):
        max_d = max(max_d, a[i + 1] - a[i])
    print(k - max_d)


if __name__ == "__main__":
    main()
