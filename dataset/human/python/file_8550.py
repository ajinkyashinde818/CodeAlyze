def solve(string):
    k, n, *a = map(int, string.split())
    b = [a[-1]] + [_a + k for _a in a]
    return str(min(a1 - a0 for a0, a1 in zip(a, b)))


if __name__ == '__main__':
    import sys
    print(solve(sys.stdin.read().strip()))
