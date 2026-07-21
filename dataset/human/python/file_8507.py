import math
import sys

stdin = sys.stdin

ns = lambda: stdin.readline().rstrip()
ni = lambda: int(stdin.readline().rstrip())
nm = lambda: map(int, stdin.readline().split())
nl = lambda: list(map(int, stdin.readline().split()))
mod = 10**9 + 7 
sys.setrecursionlimit(1000010)


K,N = nm()
A  = nl()

maxL = 0
for i in range(N-1):
    if A[i+1]-A[i] > maxL: 
        maxL = A[i+1]-A[i]

if A[0]+K - A[N-1] > maxL:
    maxL = A[0]+K - A[N-1]

print(K - maxL )
