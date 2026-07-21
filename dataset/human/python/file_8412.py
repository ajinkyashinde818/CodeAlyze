from operator import add
from functools import reduce

k, n = map(int, input().split(' '))
aa = list(map(int, input().split(' ')))

dists = [aa[0] + k - aa[-1]]
for i in range(1, len(aa)):
    dists.append(aa[i] - aa[i - 1])

print(k - max(dists))
