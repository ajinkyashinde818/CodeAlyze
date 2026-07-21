import math
from itertools import combinations
from itertools import combinations_with_replacement
from itertools import product
from collections import defaultdict
from collections import deque
from collections import Counter
import heapq


def input_li():
    return list(map(int, input().split()))


def input_int():
    return int(input())


N = input_int()
A_LI = input_li()
dp = [[0] * 2 for _ in range(N)]
dp[0][0] = A_LI[0]
dp[0][1] = -A_LI[0]
for i in range(1, N):
    dp[i][0] = max(dp[i - 1][0] + A_LI[i], dp[i - 1][1] - A_LI[i])
    dp[i][1] = max(dp[i - 1][0] - A_LI[i], dp[i - 1][1] + A_LI[i])
print(dp[-1][0])
