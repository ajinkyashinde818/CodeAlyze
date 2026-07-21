import sys
def input(): return sys.stdin.readline().strip()
def mapint(): return map(int, input().split())
sys.setrecursionlimit(10**9)

N = int(input())
S = list(input())
mod = 10**9+7
from collections import Counter
c = Counter(S)
lis = []
ans = 1
for _, cnt in c.most_common():
    ans *= (cnt+1)
    ans %= mod
print((ans-1)%mod)
