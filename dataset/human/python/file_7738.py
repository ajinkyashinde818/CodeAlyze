import sys
import os

MOD = 10 ** 9 + 7


def main():
    if os.getenv("LOCAL"):
        sys.stdin = open("input.txt", "r")

    x = int(sys.stdin.buffer.readline().rstrip())
    print('ABC' if x < 1200 else 'ARC')


if __name__ == '__main__':
    main()
