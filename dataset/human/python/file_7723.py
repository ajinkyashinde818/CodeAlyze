import sys

readline = sys.stdin.readline
MOD = 10 ** 9 + 7
INF = float('INF')
sys.setrecursionlimit(10 ** 5)


def main():
    x = int(readline())

    if x < 1200:
        print("ABC")
    else:
        print("ARC")


if __name__ == '__main__':
    main()
