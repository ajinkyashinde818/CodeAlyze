import bisect, collections, copy, heapq, itertools, math, string
import sys
def I(): return int(sys.stdin.readline().rstrip())
def MI(): return map(int, sys.stdin.readline().rstrip().split())
def LI(): return list(map(int, sys.stdin.readline().rstrip().split()))
def S(): return sys.stdin.readline().rstrip()
def LS(): return list(sys.stdin.readline().rstrip().split())

K, N = MI()
A = LI()
A_dif = []

for i in range(1, N):
    a = A[i] - A[i - 1]
    A_dif.append(a)
A_dif.append(A[0] + K - A[-1])

print(K - max(A_dif))
