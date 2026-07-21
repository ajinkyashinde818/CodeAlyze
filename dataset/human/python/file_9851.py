import sys
input=sys.stdin.readline
sys.setrecursionlimit(10 ** 6)
from collections import defaultdict
import fractions
import math
from collections import deque
from bisect import bisect_left
from bisect import insort_left
import itertools
from heapq import heapify
from heapq import heappop
from heapq import heappush
import heapq
import numpy as np
INF = float("inf")
#d = defaultdict(int)
#d = defaultdict(list)
#N = int(input())
#A = list(map(int,input().split()))
#S = list(input())
#S.remove("\n")
#N,M = map(int,input().split())
#S,T = map(str,input().split())
#A = [int(input()) for _ in range(N)]
#S = [input() for _ in range(N)]
#A = [list(map(int,input().split())) for _ in range(N)]
N,K = map(int,input().split())
A = list(map(int,input().split()))
if K <= 3 * N:
    cur = 1
    for i in range(K):
        cur = A[cur-1]
    print(cur)
else:
    d = defaultdict(int)
    cur = 1
    for i in range(3*N):
        cur = A[cur-1]
        d[cur] += 1
    if d[1] != 0:
        cur = 1
        for i in range(1,N+1):
            cur = A[cur-1]
            if cur == 1:
                f = i
        num = K % f
        if num == 0:
            print(1)
        else:
            cur = 1
            for i in range(num):
                cur = A[cur-1]
            print(cur)
    else:
        cnt = 0
        for i in range(1,N+1):
            if d[i] == 1:
                cnt += 1
        cur = 1
        for i in range(cnt+1):
            cur = A[cur-1]
        start = cur
        for i in range(1,N+1):
            cur = A[cur-1]
            if cur == start:
                f = i
                break
        K = K - cnt -1
        num = K % f
        if num == 0:
            print(start)
        else:
            cur = start
            for i in range(num):
                cur = A[cur-1]
            print(cur)
