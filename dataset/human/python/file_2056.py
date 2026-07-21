from collections import Counter
from operator import mul
from functools import reduce

N = int(input())
S = input()

char_num = Counter(list(S))
cnt = reduce(mul, [c+1 for c in char_num.values()]) - 1
print(cnt % (10**9+7))
