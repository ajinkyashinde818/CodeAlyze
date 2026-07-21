from itertools import product
from math import ceil


def solve(string):
    d, g, *pc = map(int, string.split())
    g //= 100
    p = [_p for _p in pc[::2]]
    c = [_c // 100 for _c in pc[1::2]]
    ans = 1000
    for f in product([True, False], repeat=d):
        sums = sum([(i + 1) * _p + _c for i, (_f, _p, _c) in enumerate(zip(f, p, c)) if _f])
        counts = sum([_p for _f, _p in zip(f, p) if _f])
        if g <= sums:
            ans = min(ans, counts)
            continue

        indices = [i + 1 for i, _f in enumerate(f) if not _f]
        tmp = ceil((g - sums) / indices[-1])
        if tmp < p[indices[-1] - 1]:
            ans = min(ans, counts + tmp)
    return str(ans)


if __name__ == '__main__':
    n, g = map(int, input().split())
    print(solve('{} {}\n'.format(n, g) + '\n'.join([input() for _ in range(n)])))
