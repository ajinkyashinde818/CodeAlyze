def examB():
    K, S = LI()
    ans = 0
    for x in range(K + 1):
        if 0 <= S - x <= K:
            ans += S - x  + 1
        elif K < S - x <= 2 * K:
            ans += K - (S - x - K) + 1
    print(ans)

import sys
from collections import Counter,defaultdict,deque
def I(): return int(sys.stdin.readline())
def LI(): return list(map(int,sys.stdin.readline().split()))
def LS(): return sys.stdin.readline().split()
def S(): return sys.stdin.readline().strip()
mod = 10**9 + 7
inf = float('inf')

examB()
