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
N = int(input())
ans = 0
if N%2 == 1:
    print(0)
else:
    N //= 2
    while N >= 5:
        ans += N//5
        N = N //5
    print(ans)
