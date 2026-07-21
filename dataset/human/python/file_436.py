import math  # noqa
import bisect  # noqa
import queue  # noqa


if __name__ == '__main__':
    N = int(input())
    A = list(map(int, input().split()))

    cnt_neg = 0
    abs_min = 1000000005
    for a in A:
        abs_min = min(abs_min, abs(a))
        if a < 0:
            cnt_neg += 1

    ans = 0
    for a in A:
        ans += abs(a)

    if cnt_neg % 2 != 0:
        ans -= 2 * abs_min

    print(ans)
