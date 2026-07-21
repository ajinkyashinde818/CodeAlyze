import math
import sys
from collections import defaultdict
from itertools import product, permutations, combinations

sys.setrecursionlimit(10**7)
def input():
    return sys.stdin.readline()[:-1]


N = int(input())
if N % 2:
    print(0)
    exit()
else:
    N //= 2

ans = 0
while N > 0:
    N //= 5
    ans += N
print(ans)
