import sys
import itertools
from math import ceil

read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline

in_n = lambda: int(readline())
in_nn = lambda: map(int, readline().split())
in_nl = lambda: list(map(int, readline().split()))
in_na = lambda: map(int, read().split())
in_s = lambda: readline().rstrip().decode('utf-8')


def main():
    D, G = in_nn()
    p = [0] * D
    c = [0] * D
    for i in range(D):
        a, b = in_nn()
        p[i] = a
        c[i] = b

    comb = itertools.product([0, 1], repeat=D)
    ans = 10**9 + 7

    for com in comb:
        score = 0
        prob = 0
        for i, x in enumerate(com):
            if x == 1:
                prob += p[i]
                score += c[i] + p[i] * 100 * (i + 1)

        for i in range(D - 1, -1, -1):
            if score >= G:
                break
            if com[i] == 0:
                pt = ceil((G - score) / (100 * (i + 1)))
                pt = min(pt, p[i] - 1)
                score += pt * 100 * (i + 1)
                prob += pt

        if score >= G:
            ans = min(ans, prob)

    print(ans)


if __name__ == '__main__':
    main()
