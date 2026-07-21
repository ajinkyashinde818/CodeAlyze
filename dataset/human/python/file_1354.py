import sys
def input(): return sys.stdin.readline().strip()
def mapint(): return map(int, input().split())
sys.setrecursionlimit(10**9)

N = int(input())
As = list(mapint())
from itertools import accumulate

cum = list(accumulate(As))
ans = 10**18
for i in range(N-1):
    ans = min(ans, abs(cum[i]-(cum[-1]-cum[i])))
print(ans)
