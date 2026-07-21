import collections
import math


def main():
    n, k, s = map(int, input().split())
    if s > 1:
        print(" ".join([str(s)] * k + [str(s - 1)] * (n - k)))
    else:
        print(" ".join([str(s)] * k + [str(s + 1)] * (n - k)))


if __name__ == '__main__':
    main()
