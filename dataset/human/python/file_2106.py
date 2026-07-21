import sys
import collections


def solve():
    readline = sys.stdin.buffer.readline
    mod = 10 ** 9 + 7
    n = int(readline())
    s = str(readline().rstrip().decode('utf-8'))
    s = collections.Counter(s)
    t = 1
    for k, v in s.items():
        t *= (v + 1)
        t %= mod
    print(t - 1)


if __name__ == '__main__':
    solve()
