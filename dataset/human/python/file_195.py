def main():
    r, g, b, n = map(int, input().split())
    ans = 0
    x, y = 0, 0
    while r*x <= n:
        m = n - r*x
        y = 0
        while g*y <= m:
            if (m - g*y) % b == 0:
                ans += 1
            y += 1
        x += 1
    print(ans)

if __name__ == "__main__":
    main()
