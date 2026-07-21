import sys
import math
import numpy as np
from collections import defaultdict
input = sys.stdin.readline


def log(*args):
    print(*args, file=sys.stderr)


def main():
    np.set_printoptions(threshold=20)
    N = int(input())
    d = defaultdict(int)
    for i in range(2, math.ceil(math.sqrt(N))):
        while N % i == 0:
            d[i] += 1
            N //= i
    if N != 1:
        d[N] += 1

    ans = 0
    for key in d:
        val = d[key]
        tmp = 0
        count = 0
        for i in range(1, val):
            tmp += i
            count += 1
            if tmp == val:
                break
            elif tmp > val:
                count -= 1
                break
        ans += max(count, 1)
    print(ans)


if __name__ == '__main__':
    main()
