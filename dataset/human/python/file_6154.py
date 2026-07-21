def slove():
    import sys
    input = sys.stdin.readline
    a, b, c = list(map(int, input().rstrip('\n').split()))
    cnt = 0
    t = min(c, a)
    c -= t
    a -= t
    cnt += t
    t = min(c, b)
    c -= t
    b -= t
    cnt += (t * 2)
    if b > 0:
        print(cnt + b)
    else:
        print(cnt + min(c, 1))


if __name__ == '__main__':
    slove()
