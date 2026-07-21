import sys

readline = sys.stdin.readline
MOD = 10 ** 9 + 7
INF = float('INF')
sys.setrecursionlimit(10 ** 5)


def main():
    N, R = map(int, readline().split())

    if N >= 10:
        print(R)
    else:
        print(R + 100 * (10-N))


if __name__ == '__main__':
    main()
