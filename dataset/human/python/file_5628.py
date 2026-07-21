import sys
import math  # noqa
import bisect  # noqa
import queue  # noqa


def input():
    return sys.stdin.readline().rstrip()


def main():
    S = input()

    l = 0
    r = len(S) - 1

    cnt = 0
    while l < r:
        if S[l] == S[r]:
            l += 1
            r -= 1
        elif S[l] != 'x' and S[r] == 'x':
            r -= 1
            cnt += 1
        elif S[l] == 'x' and S[r] != 'x':
            l += 1
            cnt += 1
        else:
            return print(-1)

    print(cnt)


if __name__ == '__main__':
    main()
