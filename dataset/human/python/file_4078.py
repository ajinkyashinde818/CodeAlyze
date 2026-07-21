import bisect
import copy
import heapq
import sys
import itertools
import math
import queue
input = sys.stdin.readline
sys.setrecursionlimit(1000000)
mod = 10 ** 9 + 7

def read_values(): return map(int, input().split())
def read_index(): return map(lambda x: int(x) - 1, input().split())
def read_list(): return list(read_values())
def read_lists(N): return [read_list() for n in range(N)]


def f(N):
    D = {}

    for i in range(2, int(N ** 0.5) + 1):
        c = 0
        while N % i == 0:
            c += 1
            N //= i
        if c > 0:
            D[i] = c
        if N == 1:
            break
            
    if N != 1:
        D[N] = 1
    return D


def main():
    N = int(input())
    D = f(N)

    res = 0
    for k, v in D.items():
        t = 1
        while t <= v:
            v -= t
            t += 1
        res += t - 1
    print(res)       


if __name__ == "__main__":
    main()
