import sys

readline = sys.stdin.readline
MOD = 10 ** 9 + 7
INF = float('INF')
sys.setrecursionlimit(10 ** 5)


def main():
    from math import gcd

    A, B = map(int, readline().split())

    print(A * B // gcd(A, B))


if __name__ == '__main__':
    main()
