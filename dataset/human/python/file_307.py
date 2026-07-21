from collections import deque

N = int(input())
A = list(map(int, input().split()))
minAbs = 10**10
countMinus = 0
S = 0
for a in A:
  countMinus += (1 if a < 0 else 0)
  S += abs(a)
  minAbs = min(minAbs, abs(a))
print(S-2*(0 if countMinus % 2 == 0 else minAbs))
