import sys
import collections


def solve():
    readline = sys.stdin.buffer.readline
    mod = 10 ** 9 + 7
    n, m = list(map(int, readline().split()))
    d = collections.defaultdict(list)
    for _ in range(m):
        a, b = list(map(int, readline().split()))
        if a == 1 or a == n:
            if a not in d[b]:
                d[b] += [a]
        elif b == 1 or b == n:
            if b not in d[a]:
                d[a] += [b]
    for k, v in d.items():
        if k != 1 and k != n:
            if len(v) == 2:
                print("POSSIBLE")
                exit()
    print("IMPOSSIBLE")


if __name__ == '__main__':
    solve()
