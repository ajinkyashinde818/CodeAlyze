import sys
import os


def calc(n):
    return 100 * (10 - n)


def main():
    if os.getenv("LOCAL"):
        sys.stdin = open("input.txt", "r")

    N, R = map(int, sys.stdin.readline().split())

    if 10 > N:
        print(calc(N) + R)
    else:
        print(R)


if __name__ == '__main__':
    main()
