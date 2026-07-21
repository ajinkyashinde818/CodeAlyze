import sys


def solve():
    input = sys.stdin.readline
    mod = 10 ** 9 + 7
    r, g, b, n = list(map(int, input().rstrip('\n').split()))
    cnt = 0
    for i in range(n+1):
        for j in range(n+1):
            if r * i + g * j > n:
                break
            else:
                if (n - r * i - g * j) % b == 0:
                    cnt += 1
    print(cnt)


if __name__ == '__main__':
    solve()
