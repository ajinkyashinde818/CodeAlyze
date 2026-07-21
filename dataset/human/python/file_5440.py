import sys

read = sys.stdin.read
readline = sys.stdin.readline
readlines = sys.stdin.readlines
sys.setrecursionlimit(10 ** 9)
INF = 1 << 60
MOD = 1000000007


def main():
    N = readline().strip()

    if '9' in N:
        print('Yes')
    else:
        print('No')

    return


if __name__ == '__main__':
    main()
