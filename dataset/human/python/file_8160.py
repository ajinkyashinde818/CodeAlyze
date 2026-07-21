import bisect
import heapq
import itertools
import math
import os
import re
import string
import sys
from collections import Counter, deque, defaultdict
from decimal import Decimal
from fractions import gcd
from functools import lru_cache, reduce
from operator import itemgetter

import numpy as np

if os.getenv("LOCAL"):
    sys.stdin = open("_in.txt", "r")

K, S = list(map(int, sys.stdin.readline().split()))

a = np.array(np.meshgrid(np.arange(K + 1), np.arange(K + 1))).sum(axis=0)
print(((S - K <= a) & (a <= S)).sum())
