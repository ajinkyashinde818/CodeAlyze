import collections
import functools
import operator
N = int(input())
S = str(input())
c = collections.Counter(S)
count = c.most_common()
count = [x+1 for _, x in count]
count = functools.reduce(operator.mul, count) -1
print(int(count%(10**9+7)))
