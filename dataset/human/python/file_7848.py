def main():
    n, k, s = map(int, input().split())

    other = 0
    if s == 10**9:
        other = 10**9 - 1
    else:
        other = s + 1

    if n > k:
        ans = [s for _ in range(k)] + [other for _ in range(n-k)]
    else:
        ans = [s for _ in range(n)]

    print(*ans)

if __name__ == "__main__":
    main()
