import sys

readline = sys.stdin.readline
MOD = 10 ** 9 + 7
INF = float('INF')
sys.setrecursionlimit(10 ** 5)


def main():
    n = int(readline())
    a = list(map(int, readline().split()))

    ans = INF
    snuke = 0
    arai_san = sum(a)

    for x in a[:-1]:
        snuke += x
        arai_san -= x
        ans = min(ans, abs(snuke - arai_san))

    print(ans)


if __name__ == '__main__':
    main()
