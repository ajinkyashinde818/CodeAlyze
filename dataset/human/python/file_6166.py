import sys

readline = sys.stdin.readline
MOD = 10 ** 9 + 7
INF = float('INF')
sys.setrecursionlimit(10 ** 5)


def main():
    a, b, c = map(int, readline().split())
    ans = min(c, a + b + 1) + b
    print(ans)


if __name__ == '__main__':
    main()
