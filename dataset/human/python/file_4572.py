def main():
    N = int(input())
    A = []
    x = N
    l = int(N ** 0.5)
    for t in range(2, l + 1):
        while x % t == 0:
            A.append(t)
            x //= t

    if x > 1:
        A.append(x)

    import collections
    ans = 0
    for v in collections.Counter(A).values():
        for n in range(1, 41):
            if v < n * (n + 1) // 2:
                ans += n - 1
                break

    print(ans)


if __name__ == '__main__':
    main()
