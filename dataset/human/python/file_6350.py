import math
import time
from collections import deque
from copy import deepcopy

t = time.time()
def iip():
    ret = [int(i) for i in input().split()]
    if len(ret) == 1:
        return ret[0]
    return ret


def main():
    n = iip()

    if n == 0:
        print(0)
        exit()
    if n % 2 == 1:
        print(0)
        exit()

    ret = int(0)

    num = 10
    while num <= n:
        ret += n // num
        num *= 5

    print(int(ret))


main()
