import sys


def solve():
    readline = sys.stdin.buffer.readline
    mod = 10 ** 9 + 7
    n = int(readline())
    if n % 2 == 0:
        cnt = 0
        for i in range(1, 10 ** 20):
            md = pow(5, i) * 2
            if md <= n:
                cnt += n // md
            else:
                break
        print(cnt)
    else:
        print(0)


if __name__ == '__main__':
    solve()
