import sys

readline = sys.stdin.readline
MOD = 10 ** 9 + 7
INF = float('INF')
sys.setrecursionlimit(10 ** 5)


def main():
    x, y = input().split()

    a = int(x, 16)
    b = int(y, 16)

    if a < b:
        print("<")
    elif a > b:
        print(">")
    else:
        print("=")


if __name__ == '__main__':
    main()
