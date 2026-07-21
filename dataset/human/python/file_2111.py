import sys
import itertools as it
input = sys.stdin.readline


def log(*args):
    print(*args, file=sys.stderr)


def main():
    n = int(input())
    ss = list(input().strip())
    m = {}
    for c in ss:
        if c not in m:
            m[c] = 0
        m[c] += 1
    ans = 1
    for k in m:
        ans *= m[k] + 1
        ans %= 10**9 + 7
    print(ans - 1)


if __name__ == '__main__':
    main()
