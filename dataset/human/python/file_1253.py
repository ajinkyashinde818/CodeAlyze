def main():
    _ = int(input())
    aa = list(map(int, input().split()))
    x = aa[0]
    y = sum(aa[1:])
    res = abs(x - y)
    for a in aa[1:-1]:
        x += a
        y -= a
        res = min(res, abs(x - y))
    print(res)


if __name__ == '__main__':
    main()
