def main():
    r, g, b, n = map(int, raw_input().split())
    s = 0
    for i in range(n // r + 1):
        c = i * r
        if c == n:
            s += 1
            continue
        for j in range((n - c) // g + 1):
            cc = c + j * g
            if cc <= n and (n - cc) % b == 0:
                s += 1
    print s


if __name__ == '__main__':
    main()
