import sys


def solve():
    readline = sys.stdin.buffer.readline
    mod = 10 ** 9 + 7
    k, s = list(map(int, readline().split()))
    cnt = 0
    for x in range(k + 1):
        for y in range(k + 1):
            ts = s - x - y
            if 0 <= ts <= k:
                cnt += 1
    print(cnt)


if __name__ == '__main__':
    solve()
