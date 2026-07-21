import sys
import itertools
input = sys.stdin.readline
sys.setrecursionlimit(100000)


def read_values():
    return map(int, input().split())


def read_index():
    return map(lambda x: x - 1, map(int, input().split()))


def read_list():
    return list(read_values())


def read_lists(N):
    return [read_list() for n in range(N)]


def main():
    N, R = read_values()
    print(R if N >= 10 else R + 100 * (10 - N))


if __name__ == "__main__":
    main()
