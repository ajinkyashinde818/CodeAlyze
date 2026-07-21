from math import ceil
from itertools import product


def main():
    d, g = map(int, input().split())
    g //= 100
    p = [0] * d
    c = [0] * d
    r = [0] * d
    for i in range(d):
        _p, _c = map(int, input().split())
        _c //= 100
        p[i] = _p
        c[i] = _c
    ans = sum(p)
    for m in product((0, 1), repeat=d):
        t = 0
        a = 0
        for i in range(d):
            if m[i] == 1:
                t += p[i] * (i + 1) + c[i]
                a += p[i]
        for i in range(d - 1, -1, -1):
            if m[i] == 1:
                continue
            pi = p[i] * (i + 1)
            if t + pi >= g:
                a += ceil(max(g - t, 0) / (i + 1))
                break
            t += pi + c[i]
            a += p[i]
        ans = min(a, ans)
    print(ans)


if __name__ == '__main__':
    main()
