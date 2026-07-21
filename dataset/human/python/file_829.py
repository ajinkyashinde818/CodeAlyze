import sys

read = sys.stdin.read
readline = sys.stdin.readline
readlines = sys.stdin.readlines
sys.setrecursionlimit(10 ** 9)
INF = 1 << 60
MOD = 1000000007


def main():
    N, R = map(int, readline().split())

    if N >= 10:
        print(R)
    else:
        print(R + 100 * (10 - N))

    return


if __name__ == '__main__':
    main()
