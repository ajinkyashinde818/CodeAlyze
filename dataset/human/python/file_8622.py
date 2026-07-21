def resolve():
    k, n = map(int, input().split())
    a = sorted([int(i) for i in input().split()])

    a_diff = [a[i] - a[i-1] for i in range(1, len(a))]
    a_diff.append((k - a[-1]) + a[0])
    a_diff = sorted(a_diff, reverse=True)

    print(sum(a_diff[1:]))


resolve()
