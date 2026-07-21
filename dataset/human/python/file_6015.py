import sys


def solve():
    readline = sys.stdin.buffer.readline
    mod = 10 ** 9 + 7
    n = int(readline())
    a = list(map(int, readline().split()))
    b = list(map(int, readline().split()))
    c = list(map(int, readline().split()))
    le = -10 ** 10
    t = 0
    for av in a:
        t += b[av-1]
        if av - le == 1:
            t += c[le-1]
        le = av
    print(t)


if __name__ == '__main__':
    solve()
