from itertools import accumulate
from math import*
from collections import deque
from collections import defaultdict
from itertools import permutations
from heapq import*
from collections import Counter
from itertools import*
from bisect import bisect_left,bisect_right
from copy import deepcopy
inf = 10**18
mod = 10**9+7
from functools import reduce
import sys
sys.setrecursionlimit(10**7)

n = int(input())
a = list(map(int,input().split()))
dp = [[0]*2 for i in range(n+1)]
dp[0][1] = -inf
for i in range(n):
    dp[i+1][0] = max(dp[i][0]+a[i],dp[i][1]-a[i])
    dp[i+1][1] = max(dp[i][0]-a[i],dp[i][1]+a[i])
print(dp[n][0])
