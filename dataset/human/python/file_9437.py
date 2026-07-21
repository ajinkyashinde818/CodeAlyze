def solve(string):
    n, k, *a = map(int, string.split())
    a, t, p = [_a - 1 for _a in a], [0] * n, 0
    for i, _ in enumerate(a, 1):
        t[a[p]] = i
        p = a[p]
        if i == k:
            return str(p + 1)
    k = (k - t[a[p]] + 1) % (t[p] - t[a[p]] + 1)
    for _ in range(k):
        p = a[p]
    return str(p + 1)


if __name__ == '__main__':
    import sys
    print(solve(sys.stdin.read().strip()))
