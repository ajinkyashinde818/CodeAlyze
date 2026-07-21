import math
import sys
readline = sys.stdin.readline


def main():
    n = int(readline().rstrip())
    if n % 2 == 1:
        print(0)
    else:
        n = n // 2
        num = 0
        for i in range(1, 100):
            num += n // (5 ** i)
        print(num)


if __name__ == '__main__':
    main()
