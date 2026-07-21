import sys

readline = sys.stdin.buffer.readline
mod = 10 ** 9 + 7
n = int(readline())
a = list(map(int, readline().split()))
b = list(map(int, readline().split()))


def f(md, pos):
    res = 0
    fpos = -2
    for av in a:
        while True:
            if pos != -1 and av + b[pos] >= md:
                pos -= 1
            else:
                if fpos == -2:
                    fpos = pos
                res += pos + 1
                break
    return res, fpos


def solve():
    dp = [0] * 31
    for i in range(28, -1, -1):
        md = pow(2, i + 1)
        for j in range(n-1, -1, -1):
            b[j] %= md
            a[j] %= md
        a.sort()
        b.sort()
        pos = n - 1
        res3, pos = f(md // 2 * 3, pos)
        res2, pos = f(md // 2 * 2, pos)
        res1, pos = f(md // 2, pos)
        dp[i] += (n * n - (res1 + res3 - res2)) % 2
    t = 0
    for i in range(31):
        t += pow(2, i) * dp[i]
    print(t)


if __name__ == '__main__':
    solve()
