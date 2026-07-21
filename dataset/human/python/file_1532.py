import sys

readline = sys.stdin.readline
MOD = 10 ** 9 + 7
INF = float('INF')
sys.setrecursionlimit(10 ** 5)


def main():
    n, m = map(int, readline().split())
    a = [input() for _ in range(n)]
    b = [input() for _ in range(m)]

    for row in range(n - m + 1):
        for col in range(n - m + 1):
            cur = [a[r][col:col + m] for r in range(row, row + m)]
            if cur == b:
                return print("Yes")

    print("No")


if __name__ == '__main__':
    main()
