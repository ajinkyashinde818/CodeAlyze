import sys
import itertools
input = sys.stdin.readline
sys.setrecursionlimit(10 ** 7)


def main():
    n = int(input())
    a = list(map(int, input().split()))
    s = sum(a)
    t = list(itertools.accumulate(a))
    print(min(abs(s-2*t[i]) for i in range(0, n-1)))


if __name__ == '__main__':
    main()
