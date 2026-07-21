import math
import random
from operator import itemgetter
import re
import sys
from itertools import accumulate
from collections import defaultdict
from collections import deque
from bisect import bisect_left,bisect
from heapq import heappop,heappush
from fractions import gcd
from copy import deepcopy
import functools
N = int(input())
x = [int(i) for i in input().split()]
mod = 10**9+7
start = 1
st = 1
st_list = [0] * N
st_rev = [0] * N
for i in range(N-1):
    st *= (i+1)
    st %= mod
    st_list[i] = st
    st_rev[i] = pow(st,mod-2,mod)
all_dis = 0
for i in range(N-1):
    far = x[i+1]-x[i]
    all_dis += far*start*st_list[N-2]*st_rev[i]
    start = (start*(i+2)+st_list[i])%mod
    all_dis %= mod
print(all_dis)
