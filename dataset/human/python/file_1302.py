from itertools import accumulate

N = int(input())
lst = list(map(int, input().split()))

cumsum = list(accumulate(lst))

mi = 2 * 10 ** 9
su = cumsum[-1]
for i in range(len(cumsum)-1):
  mi = min(mi, abs(cumsum[i] - (su-cumsum[i])))
print(mi)
