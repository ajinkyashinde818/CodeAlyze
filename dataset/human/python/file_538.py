import sys
import bisect
import collections
import fractions
import heapq


def slove():
    input = sys.stdin.readline
    n = int(input().rstrip('\n'))
    a = list(map(int, input().rstrip('\n').split()))
    cnt = 0
    t = 0
    for i in range(n):
        if a[i] < 0:
            cnt += 1
        a[i] = abs(a[i])
        t += a[i]
    a.sort()
    if cnt % 2 == 0:
        print(t)
    else:
        print(t - abs(a[0]) * 2)


if __name__ == '__main__':
    slove()
