import sys


def solve():
    readline = sys.stdin.buffer.readline
    mod = 10 ** 9 + 7
    k, n = list(map(int, readline().split()))
    a = list(map(int, readline().split()))
    a = [a[-1] - k] + a + [k + a[0]]
    mt = 10 ** 10
    for i in range(1, len(a) - 1):
        mt = min(mt, k - abs(a[i] - a[i-1]), k - abs(a[i] - a[i+1]))
    print(mt)


if __name__ == '__main__':
    solve()
