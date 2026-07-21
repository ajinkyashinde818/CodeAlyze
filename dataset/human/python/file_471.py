import math
import numpy as np
from fractions import gcd
import fractions
import statistics
import collections
from functools import reduce
import itertools
from collections import defaultdict

N = int(input())
A = list(map(int, input().split()))

cnt = 0
cnt0 = 0
for i in range(N):
    if (A[i] == 0):
        cnt0 +=1
    if (A[i] < 0):
        cnt +=1

if (cnt%2 == 0 or cnt0>=1):
    print(sum(np.abs(np.array(A))))
else:
    print(sum(np.abs(np.array(A)))-min(np.abs(np.array(A)))*2)
