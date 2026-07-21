import sys
import re

read = sys.stdin.read
readline = sys.stdin.buffer.readline
sys.setrecursionlimit(10 ** 8)
INF = float('inf')
MOD = 10 ** 9 + 7


def main():
    X, Y = input().split()
    if X < Y:
        print('<')
    elif X > Y:
        print('>')
    else:
        print('=')


if __name__ == '__main__':
    main()
