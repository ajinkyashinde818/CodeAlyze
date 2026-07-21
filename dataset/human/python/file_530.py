def main():
    n = int(input())
    a = list(map(int, input().split()))

    cnt = 0
    for e in a:
        if e < 0:
            cnt += 1

    a = list(map(abs, a))
    a.sort()
    if cnt % 2:
        ans = sum(a[1:]) - a[0]
    else:
        ans = sum(a)

    print(ans)


if __name__ == "__main__":
    main()
