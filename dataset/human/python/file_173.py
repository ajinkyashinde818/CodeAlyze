import sys
input = sys.stdin.readline
from itertools import product


def read():
    R, G, B, N = map(int, input().strip().split())
    return R, G, B, N


def solve(R, G, B, N):
    ans = 0
    for r, g in product(range(3001), range(3001)):
        v = N - R * r - G * g
        b = v // B
        if v >= 0 and B * b == v:
            ans += 1
    return ans


if __name__ == '__main__':
    inputs = read()
    outputs = solve(*inputs)
    if outputs is not None:
        print("%s" % str(outputs))
