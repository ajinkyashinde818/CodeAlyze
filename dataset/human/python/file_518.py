import numpy as np
from collections import defaultdict
from functools import reduce

n = int(input())
A = list(map(int, input().split()))

S = reduce(lambda x, y: abs(x)+abs(y), A)


if len(list(filter(lambda x: x<0, A)))%2 == 0:
    print(S)
else:
    print(S - 2*min(abs(x) for x in A))
