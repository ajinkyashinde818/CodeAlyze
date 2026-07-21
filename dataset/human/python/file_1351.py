def slove():
    import sys
    input = sys.stdin.readline
    n = int(input().rstrip('\n'))
    t = 0
    mt = 10 ** 10
    a = list(map(int, input().rstrip('\n').split()))
    s = sum(a)
    for i in range(n-1):
        t += a[i]
        mt = min(mt, abs(s - t - t))
    print(mt)


if __name__ == '__main__':
    slove()
