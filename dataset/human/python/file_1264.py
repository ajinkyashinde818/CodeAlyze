import sys
from itertools import accumulate
import bisect
n = int(input())
a_ls = [int(i) for i in sys.stdin.readline().split()]
sum_ls = [i for i in accumulate(a_ls[:-1])]
sum_a = sum(a_ls)
sum_ls.sort()
ind = bisect.bisect_left(sum_ls, sum_a / 2)
best = 10 ** 18
if ind < n - 1 and abs(sum_a / 2 - sum_ls[ind]) * 2 < best:
    best = abs(sum_a / 2 - sum_ls[ind]) * 2
if ind > 0 and abs(sum_a / 2 - sum_ls[ind - 1]) * 2 < best:
    best = abs(sum_a / 2 - sum_ls[ind - 1]) * 2
print(int(best))
