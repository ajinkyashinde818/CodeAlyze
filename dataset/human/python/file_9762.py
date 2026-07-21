import sys
import math  # noqa
import bisect  # noqa
import queue  # noqa


def input():
    return sys.stdin.readline().rstrip()


def main():
    N, K = map(int, input().split())
    A = list(map(int, input().split()))

    res = K
    step = [-1 for _ in range(N)]
    que = queue.Queue()
    que.put(0)
    step[0] = 0
    while not que.empty():
        nc = que.get()
        nn = A[nc]
        nn -= 1
        res -= 1
        if step[nn] == -1:
            step[nn] = step[nc] + 1
            if res == 0:
                return print(nn + 1)
            que.put(nn)
        else:
            start = nn
            closer = [nn]
            while True:
                nn = A[nn] - 1
                if nn != start:
                    closer.append(nn)
                else:
                    break
            ans = res % len(closer)
            print(closer[ans] + 1)


if __name__ == '__main__':
    main()
